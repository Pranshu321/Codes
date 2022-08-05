# STL

## Array
- Static array is used as implementation.

## Vector
- Dynamic array is used in implementeation.

## Stack & Queues
- Both stacks and queues in C++ standard library are container adaptors. It means that they use specified container as the underlying means to store data. By default both of them use std::deque but you can use e.g. vector with.
```cpp
std::stack<int,std::vector<int>> s;
```

## Dequeue
- implemented as a linked list but as an array of pointers to blocks or arrays of data.

## List
- The STL list requires traversal in both the directions by means of forward and reverse iterator. Hence the list should be implemented as a doubly linked list.

## Priority Queue
- Priority Queue can be implemented using an array, binary search tree, linked-list, and heap data structure.

## Set
- By doing that we easily conclude that a Red-black tree used in this implementation.

## Map
- For Integer Mapping : A Balanced Binary Search Tree could be used .
- For String Mapping : Compressed Trie or something similar could be used .
