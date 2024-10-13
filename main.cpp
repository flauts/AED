#include <iostream>
#include <stack>
using namespace std;

auto fun(const string& str) {
    stack<int> numbers;
    stack<char> operators;
    string current_number = "";
    for(int i = 0; i < str.length();i++) {
        if(str[i] != '+' && str[i] != '*' && str[i] != '/' && str[i] != '-') {
            current_number+=str[i];
            if(i == str.length()-1) numbers.push(stoi(current_number));
        }else {
            numbers.push(stoi(current_number));
            current_number="";
            operators.push(str[i]);
        }
    }
    while(!operators.empty()) {
        int b = numbers.top();
        numbers.pop();
        int result = numbers.top();
        numbers.pop();
        char op = operators.top();
        operators.pop();
        if(!operators.empty()){
            if( (operators.top() == '/' || operators.top() == '*') && (op != '/' || op != '*')) {
                char op_priority = operators.top();
                operators.pop();
                int a = result;
                int c = numbers.top();
                numbers.pop();
                if(op_priority == '/') result = c / a;
                else result = c*a;
            }
        }
        if(op == '-') result = result - b;
        else if (op == '+') result = result + b;
        else if (op == '*') result = result*b;
        else if(op == '/') result = result/b;
        numbers.push(result);
    }
    return numbers.top();
}
int main() {
    cout << fun("4/2+3*2+1/5");
    return 0;
}
