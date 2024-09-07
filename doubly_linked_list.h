#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node(T val): data(val), next(nullptr),prev(nullptr){};
};

template <typename T>
class List {
    Node<T>* head;
    Node<T>* tail;
public:
    T front() {
        return head->data;
    }
    T back() {
        return tail->data;
    }
    void push_front(const T& val) {
        Node<T>* node = new Node(val);
        node->next = head;
        head->prev = node;
        head = node;
    }

    void push_back(const T& val) {
        Node<T>* node = new Node(val);
        tail->next = node;
        node->prev = tail;
    }

    T pop_front() {
        auto val = head->data;
        auto next = head->next;
        delete head;
        next->prev = nullptr;
        head = next;
        return val;
    }

    T pop_back() {
        auto val = tail->data;
        auto prev = tail->prev;
        delete tail;
        prev->next = nullptr;
        tail=prev;
        return val;
    }
    void insert(const T& val, const int& pos) {
        auto current = head;
        for(int i = 0; i < pos-1;i++) {
            if(current == nullptr) return;
            current = current->next;
        }
        Node<T>* node = new Node(val);
        node->next = current->next;
        node->prev = current;
        current->next->prev = node;
        current->next=node;
    }
    void remove(const int& pos) {
        auto current = head;
        for(int i = 0; i < pos;i++) {
            if(current == nullptr) return;
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
    T operator[](const int& pos) {
        auto current = head;
        for(int i =0; i < pos-1;i++) {
            if(current == nullptr) return -1;
            current = current->next;
        }
        return current->data;
    }

    void reverse() {
        auto temp = head;
        head = tail;
        tail = temp;
    }

    bool empty() {
        return head ==nullptr and tail ==nullptr;
    }


    List():head(nullptr),tail(nullptr){};
};


template<typename T>
Node<T>* join(Node<T>* head1, Node<T>* head2) {
    auto current1 = head1;
    auto current2 = head2;
    if(current1->data < current2->data) {
        ///xd
        ///xd
        ///
    }
    return nullptr;
}


#endif //DOUBLY_LINKED_LIST_H
