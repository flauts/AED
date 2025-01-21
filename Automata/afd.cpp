#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node {
    bool isEnd;
    unordered_map<char,Node*> next;
    Node(bool end):isEnd(end){};
};

class FiniteAutomata {
    Node* init;
    bool run(string s) {
        auto curr = init;
        for(auto e: s) {
            if(e == '0') curr = curr->next[0];
            else if(e == '1') curr = curr->next[1];
        }
        return curr->isEnd;
    }
    void addState(Node*& curr) {
        string s;
        bool end =false;
        Node* new_node;
        while(true) {
            cout<<"Desea que el estado sea Final o Inicial?\nPresione 5 para salir"<<endl;
            getline(cin,s);
            if(s == "F"){end = true; break;}
            if(s == "I"){end = false; break;}
            if(s == "5") break;
        }
        while(true) {
            cout<<"Para que digito desea que que cambie este nuevo estado?\nPresione 5 para salir"<<endl;
            getline(cin,s);
            if(s == "1"){ curr->next[1] = new Node(end); break;}
            if(s == "0"){ curr->next[0] = new Node(end); break;
        }
             if(s == "1+0") {
                Node* n = new Node(end);
                 curr->next[1] = n;
                 curr->next[0] = n;
                 break;
            }
            if(s == "5") break;
        }
    }
    void print(const Node*) {
        auto curr = init;
        while(curr != nullptr) {

        }
    }
    void change(Node*& curr) {
        string s;
        cout<<"Desea ir al estado al presionar 1 o 0?\nPresione 5 para salir"<<endl;
        while(true) {
            getline(cin,s);
            if(s == "1") {
                if(curr->next[1] == nullptr) {
                    cout<<"error, no existe un estado"<<endl;
                    break;
                }
                curr = curr->next[1];
                break;
            }
            if(s == "0") {
                if(curr->next[0] == nullptr) {
                    cout<<"error, no existe un estado"<<endl;
                    break;
                }
                curr = curr->next[0];
                break;
            }
            if(s == "5") break;
        }
    }
public:
    void on() {
        string s;
        if(init == nullptr){
            cout<<"Desea que el  estado sea Final o Inicial?"<<endl;
            getline(cin,s);
            if(s == "F") init = new Node(true);
            else if(s == "I") init = new Node(false);
        }
        auto curr = init;
        while (true) {
            cout<<"1. Agregar Estado\n2.Cambiar de Estado\n3.Correr Cadena\n4.Volver al inicio\n5.Salir"<<endl;
            getline(cin,s);
            if(s == "1") addState(curr);
            if(s == "2") change(curr);
            if(s == "3"){getline(cin,s); run(s);}
            if(s == "4") curr = init;
            if(s == "5") break;
        }
    }
};

int main() {
    FiniteAutomata afd;
    afd.on();
}