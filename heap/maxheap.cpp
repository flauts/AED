#include <vector>
using namespace std;

class MaxHeap {
public:
    int _size = 0;
    vector<int> v = {-1}; //elements start at index 1\\\

    int p(int i){return i >> 1;}// i / 2
    int r(int i){return i << 1;} // i * 2
    int l(int i){return (i << 1) + 1;}  //i * 2 + 1

public:
    bool empty() const {
        return _size == 0;
    }
    int getMax() {
        return v[1];
    }

    void shiftUp(int i) {
        if(i > _size) return; //shifting item that doesnt exist
        if(i == 1) return;
        if(v[i] > v[p(i)]) swap(v[p(i)],v[i]); // if parent samller than child, swap
        shiftUp(p(i));
    }

    int popMax() {
        int max = v[1];
        swap(v[1],v[_size--]); //swap with last and decrease size
        shiftDown(1); //let shift down reorganize
        return max;//return max
    }

    void shiftDown(int i) {
        if(i > _size) return; //shifting i that doesnt exist
        int swapId = i;
        if(l(i) <= _size && v[i] < v[l(i)]) swapId = l(i);
        //if left child exists and greater than parent then swap left
        if(r(i) <= _size && v[swapId] < v[r(i)]) swapId = r(i);
        //if right exists and its greater than current greater then swap right
        if(swapId != i) {
            swap(v[i],v[swapId]); //swap values of child and parent, after this parent will be greater than both
            shiftDown(swapId);
        }
        return;
    }

    void insert(int val) {
        if(_size+1 >= v.size()) {
            v.push_back(0);
        }
        v[++_size] = val;
        shiftUp(_size);
        return;
    }

    MaxHeap(){}

};