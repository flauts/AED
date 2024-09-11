#define MAX_SIZE 50000
#include <stdexcept>


template<typename T>
class Stack {
    T stack[MAX_SIZE];
    int top; // index of top element
public:
    Stack() : top(-1) {}

    bool isfull() const {
        return top == MAX_SIZE - 1;
    }

    bool isempty() const {
        return top == -1;
    }

    T get_top() const {
        if (isempty()) {
            throw std::out_of_range("Stack is empty");
        }
        return stack[top];
    }

    void push(T e) {
        if (isfull()) {
            throw std::overflow_error("Stack overflow");
        }
        stack[++top] = e;
    }

    T pop() {
        if (isempty()) {
            throw std::underflow_error("Stack underflow");
        }
        return stack[top--];
    }
};

class MinStack {
    Stack<int>* stack = new Stack<int>();
    Stack<int>* min_stack = new Stack<int>();
public:
    MinStack() {
    }

    void push(int val) {
        stack->push(val);
        if(min_stack->isempty()){
            min_stack->push(val);
        }
        else{
            if(min_stack->get_top() < val){
                min_stack->push(min_stack->get_top());
            }else{
                min_stack->push(val);
            }
        }
    }

    void pop() {
        min_stack->pop();
        stack->pop();
    }

    int top() {
        return stack->get_top();
    }

    int getMin() {
        return min_stack->get_top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */