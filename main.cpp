#include <iostream>
#include <string>
#include <cassert>
// #include "hash_table//hash_table_chaining.cpp"
#include "hash_table//hash_table_open_adressing.cpp"

void testHashTable(const std::string& name, HashTable<auto,auto>& table) {
    std::cout << "Testing " << name << ":\n";

    // Test insertion
    table.insert(1, "One");
    table.insert(2, "Two");
    table.insert(3, "Three");

    // Test search
    assert(table.search(1) == "One");
    assert(table.search(2) == "Two");
    assert(table.search(3) == "Three");
    std::cout << "Basic insertion and search: Passed\n";

    // Test update
    table.insert(2, "New Two");
    assert(table.search(2) == "New Two");
    std::cout << "Update existing key: Passed\n";

    // Test removal
    table.remove(2);
    try {
        table.search(2);
        std::cout << "Removal: Failed (didn't throw on removed key)\n";
    } catch (...) {
        std::cout << "Removal: Passed\n";
    }

    // Test collision handling
    table.insert(11, "Eleven"); // This should collide with 1 in a size-10 table
    assert(table.search(1) == "One");
    assert(table.search(11) == "Eleven");
    std::cout << "Collision handling: Passed\n";

    for (int i = 0; i < 100; ++i) {
        table.insert(i, "Value" + std::to_string(i));
    }
    for (int i = 0; i < 100; ++i) {
        assert(table.search(i) == "Value" + std::to_string(i));
    }
    std::cout << "Resizing: Passed\n";

    std::cout << "All tests passed for " << name << "!\n\n";
}

int main() {
    // HashTable<int, std::string> chainingTable;
    // testHashTable("Hash Table with Chaining", chainingTable);

    HashTable<int, std::string> openAddressingTable;
    testHashTable("Hash Table with Open Addressing", openAddressingTable);

    return 0;
}