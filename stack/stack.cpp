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
    int depth(const std::string& s) {
        Stack<char> stack;
        int current_depth = 0;
        int max = 0;

        for(auto c:s) {
            if(c == '(') {
                stack.push(c);
                current_depth+=1;
            }
            if(c == ')') {
                if(stack.get_top() == '(') {
                    stack.pop();
                    max =  current_depth >= max ? current_depth:max;
                    --current_depth;
                }
            }
        }

        return max;
    }
};
