template <typename T>
struct Node {
    Node* next;
    T data;
    Node(T val):next(nullptr),data(val){};
};

template <typename T>
class Queue {
    Node<T>* front;
    Node<T>* rear;
public:
    Queue():front(nullptr),rear(nullptr){}
    bool isempty() {
        return front==nullptr;
    }
    void enqueue(const T& val) {
        auto new_node = new Node(val);
        if(isempty()){
            front = rear = new_node;
            return;
        }
        rear->next = new_node;
        rear= new_node;
    }
    T dequeue() {
        auto front_val = front->data;
        auto new_front = front->next;
        delete front;
        front = new_front;
        if(front == nullptr) rear = nullptr;
        return front_val;
    }
    T get_front() {
        return front->data;
    }
    T get_rear() {
        return rear->data;
    }
};