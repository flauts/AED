#include "stack/Stack.cpp"
#include <iostream>
#include "queue/queue.cpp"
using namespace std;





int main() {
    Queue<int>q;
    q.enqueue(10);
    q.enqueue(20);
    cout<<q.get_front()<<endl;
    cout<<q.get_rear()<<endl;

}
