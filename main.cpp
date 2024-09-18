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

int main() {
    // HashTable<int, std::string> chainingTable;
    // testHashTable("Hash Table with Chaining", chainingTable);

    vector<int> a = {3,2,4};
    twoSum(a,6);

    return 0;
}