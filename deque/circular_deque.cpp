template <typename T> struct Node {
    Node* next;
    Node* prev;
    T data;
    Node(T data) : next(nullptr), prev(nullptr), data(data){};
};
class MyCircularDeque {
    Node<int>* front;
    Node<int>* rear;
    int current_size = 0;
    int max_size;

public:
    MyCircularDeque(int k) {
        front = nullptr;
        rear = nullptr;
        max_size = k;
    }

    bool insertFront(int value) {
        if (current_size == max_size) {
            return false;
        }
        auto new_element = new Node(value);
        if (isEmpty()) {
            front = rear = new_element;
            current_size += 1;
            return true;
        }

        front->prev = new_element;
        new_element->next =front;
        front = new_element;
        current_size+=1;
        return true;
    }

    bool insertLast(int value) {
        if (current_size == max_size) {
            return false;
        }
        auto new_elem = new Node(value);
        if (isEmpty()) {
            front = rear = new_elem;
            current_size += 1;
            return true;
        }
        rear->next = new_elem;
        new_elem->prev = rear;
        rear = new_elem;
        current_size+=1;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        auto temp = front;
        front = front->next;
        if(front == nullptr) {rear = nullptr;}
        else{front->prev = nullptr;}
        delete temp;
        current_size-=1;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        auto temp = rear;
        rear = rear->prev;
        if(rear == nullptr){front = nullptr;}
        else{rear->next = nullptr;}
        
        delete temp;
        current_size-=1;
        return true;

    }

    int getFront() {
        if (isEmpty())
            return -1;
        return front->data;
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return rear->data;
    }

    bool isEmpty() { return front == nullptr && rear == nullptr; }

    bool isFull() { return current_size == max_size; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */