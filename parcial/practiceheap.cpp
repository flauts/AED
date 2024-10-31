#include <vector>
using namespace std;
class MaxHeap {
public:
    vector<int> v = {-1};
    int _size = 0;

    int p(int i){ return i >> 1;}
    int l(int i){return i << 1;}
    int r(int i){return (i << 1) +1;}

public:
    void shiftUp(int i) {
        if(i == 1) return;
        if(v[p(i)] < v[i]) {
            swap(v[p(i)],v[i]);
            shiftUp(p(i));
        }
        else return;
    }

    void shiftDown(int i) {
        int swapId = i;
        if(l(i) <= _size && v[l(i)] > v[i]) swapId = l(i);
        if(r(i) <= _size && v[r(i)] > v[swapId]) swapId = r(i);
        if(swapId != i) {
            swap(v[i],v[swapId]);
            shiftDown(swapId);
        }
    }

    int pop() {
        int max = v[1];
        swap(v[1],v[_size]);
        v.pop_back();
        _size--;
        shiftDown(1);
        return max;
    }

    void insert(int val) {
        v.push_back(val);
        _size++;
        shiftUp(_size);
    }


};