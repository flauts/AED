cmake_minimum_required(VERSION 3.10)
project(AED_github)
set(CMAKE_CXX_STANDARD 17)

add_executable(Aed main.cpp linked_list/linked_list.cpp
        main.cpp
#        tree/AVL.cpp
        #        "../../AppData/Local/Temp/leetcode/editor/en/[23]Merge k Sorted Lists.cpp"
#        stack/stack.cpp
#        queue/queue.cpp
#        heap/minheap.cpp
#        heap/maxheap.cpp
#        parcial/Graph.cpp
        parcial/AVL.cpp
        #        hash_table/hash_table_chaining.cpp
#        hash_table/hash_table_open_adressing.cpp
#        tree/BST.cpp
#        tree/AVL.cpp
        #        hash_table/hash_table_open_adressing.cpp
        #        deque/circular_deque.cpp
#        stack/min_stack.cpp
)
