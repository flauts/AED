#include <iostream>
#include <vector>
using namespace std;

// Orden del árbol B+

// Estructura para el nodo
class Nodo {
public:
    bool esHoja;
    vector<int> claves;
    vector<Nodo*> hijos;
    Nodo* siguiente;  // Para conectar las hojas

    Nodo() {
        esHoja = true;
        siguiente = nullptr;
    }
};

class ArbolBPlus {
private:
    Nodo* raiz;
    int orden;
public:
    ArbolBPlus(int n) {
        raiz = new Nodo();
        orden = n;
    }

    // Función para insertar un valor
    void insertar(int valor) {
        if (raiz->claves.empty()) {
            raiz->claves.push_back(valor);
            return;
        }

        // Si la raíz está llena, dividir
        if (raiz->claves.size() >= orden) {
            Nodo* nuevaRaiz = new Nodo();
            nuevaRaiz->esHoja = false;
            nuevaRaiz->hijos.push_back(raiz);
            dividirNodo(nuevaRaiz, 0);
            raiz = nuevaRaiz;
        }

        insertarEnNodo(raiz, valor);
    }

    // Función auxiliar para insertar en un nodo
    void insertarEnNodo(Nodo* nodo, int valor) {
        // Si es hoja, insertar directamente
        if (nodo->esHoja) {
            int i = 0;
            while (i < nodo->claves.size() && nodo->claves[i] < valor) {
                i++;
            }
            nodo->claves.insert(nodo->claves.begin() + i, valor);
            return;
        }

        // Si no es hoja, buscar el hijo correspondiente
        int i = 0;
        while (i < nodo->claves.size() && valor > nodo->claves[i]) {
            i++;
        }

        Nodo* hijo = nodo->hijos[i];
        if (hijo->claves.size() >= orden) {
            dividirNodo(nodo, i);
            if (valor > nodo->claves[i]) {
                hijo = nodo->hijos[i + 1];
            }
        }
        insertarEnNodo(hijo, valor);
    }

    // Función para dividir un nodo
    void dividirNodo(Nodo* padre, int indice) {
        Nodo* hijoLleno = padre->hijos[indice];
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->esHoja = hijoLleno->esHoja;

        // Dividir las claves
        int medio = orden / 2;
        for (int i = medio; i < hijoLleno->claves.size(); i++) {
            nuevoNodo->claves.push_back(hijoLleno->claves[i]);
        }
        hijoLleno->claves.resize(medio);

        // Si no es hoja, redistribuir los hijos
        if (!hijoLleno->esHoja) {
            for (int i = medio; i < hijoLleno->hijos.size(); i++) {
                nuevoNodo->hijos.push_back(hijoLleno->hijos[i]);
            }
            hijoLleno->hijos.resize(medio + 1);
        }

        // Conectar nodos hoja
        if (hijoLleno->esHoja) {
            nuevoNodo->siguiente = hijoLleno->siguiente;
            hijoLleno->siguiente = nuevoNodo;
        }

        // Insertar en el padre
        padre->claves.insert(padre->claves.begin() + indice, hijoLleno->claves[medio - 1]);
        padre->hijos.insert(padre->hijos.begin() + indice + 1, nuevoNodo);
    }

    // Función para buscar un valor
    bool buscar(int valor) {
        Nodo* actual = raiz;
        while (!actual->esHoja) {
            int i = 0;
            while (i < actual->claves.size() && valor > actual->claves[i]) {
                i++;
            }
            actual = actual->hijos[i];
        }

        for (int i = 0; i < actual->claves.size(); i++) {
            if (actual->claves[i] == valor) {
                return true;
            }
        }
        return false;
    }

    // Función simple para eliminar un valor
    void eliminar(int valor) {
        Nodo* actual = raiz;

        // Encontrar la hoja donde debería estar el valor
        while (!actual->esHoja) {
            int i = 0;
            while (i < actual->claves.size() && valor > actual->claves[i]) {
                i++;
            }
            actual = actual->hijos[i];
        }

        // Eliminar el valor si existe
        for (int i = 0; i < actual->claves.size(); i++) {
            if (actual->claves[i] == valor) {
                actual->claves.erase(actual->claves.begin() + i);
                break;
            }
        }
    }
};

int main() {
    ArbolBPlus arbol(3);

    // Prueba de inserción
    arbol.insertar(5);
    arbol.insertar(15);
    arbol.insertar(25);
    arbol.insertar(35);
    arbol.insertar(45);

    // Prueba de búsqueda
    cout << "Buscando 15: " << (arbol.buscar(15) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando 20: " << (arbol.buscar(20) ? "Encontrado" : "No encontrado") << endl;

    // Prueba de eliminación
    arbol.eliminar(15);
    cout << "Despues de eliminar 15, buscando 15: " <<
        (arbol.buscar(15) ? "Encontrado" : "No encontrado") << endl;

    return 0;
}