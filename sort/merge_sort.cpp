#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr,int s,int h,int e) {
    vector<int> sort_arr;
    int ptr1 = s;
    int ptr2 = h+1;
    while(ptr1 <= h && ptr2 <= e) {
        if(arr[ptr1] < arr[ptr2]) {
            sort_arr.push_back(arr[ptr1]);
            ptr1++;
        }
        else if(arr[ptr2] < arr[ptr1]) {
            sort_arr.push_back(arr[ptr2]);
            ptr2++;
        }
        else {
            sort_arr.push_back(arr[ptr2]);
            sort_arr.push_back(arr[ptr1]);
            ptr1++;
            ptr2++;
        }
    }
    if(ptr1 > h) {
        for(int i = ptr2; i <= e;i++) {
            sort_arr.push_back(arr[i]);
        }
    }
    if(ptr2 > e) {
        for(int i = ptr1; i <= h;i++) {
            sort_arr.push_back(arr[i]);
        }
    }
    for(int i = 0; i < e-s+1;i++) {
        arr[s+i] = sort_arr[i];
    }

}
auto merge_sort(vector<int>& arr,int s,int e) {
    if(e-s+1 <= 1) return;
    int half = s+((e-s)/2);
    merge_sort(arr,s,half);
    merge_sort(arr,half+1,e);
    merge(arr,s,half,e);
}
int main()
{
    vector<int> arr = {5,-4,345,36,1,5,8,9,-20,100};
    merge_sort(arr,0,arr.size()-1);
    for(auto e:arr){
        cout<<e<<" ";
    }
    return 0;
}
