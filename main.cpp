#include <iostream>
#include <string>
#include <cassert>
#include "hash_table//hash_table_chaining.cpp"
// #include "hash_table//hash_table_open_adressing.cpp"
using namespace std;


vector<int> twoSum(std::vector<int>& nums, int target) {
    HashTable<int,int> ht;
    for(int i = 0; i < nums.size();i++){
        auto compl_index = ht.search(target-nums[i]);
        ht.insert(nums[i],i);
        if(compl_index != nullptr){
            return {i,*compl_index};
        }
    }
    return {};
}

int lengthOfLongestSubstring(string s) {
    HashTable<char, int> ht;
    int val = 0;
    int start_index = 0;
    int end_index = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (ht.search(c) != nullptr){
            cout << i << " " << c << " " <<*ht.search(c)<<endl;
            if(*ht.search(c) >= start_index) {
                start_index = *ht.search(c) +1;
                ht.remove(c);
            }
            else{
                *ht.search(c) = i;
            }
        }
        ht.insert(c, i);
        end_index = i;
        val = val < end_index - start_index +1 ? end_index - start_index +1 : val;
    }
    return val;
}

int main() {
    string s = "suqqjkuuxfeinpgjucmoc";
    cout << lengthOfLongestSubstring(s);
    return 0;
}