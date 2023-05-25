# Deque
It is the data structure which mainly have insertion and deletion from both ends.

## Application
- A deque can be used as both stack and queue.
- Maintaning history of the actions.
- A steal Process Scheduling Alogrithm.
- Implementing a priority queue with two types of priorities.
- Maximum/Minimum of all subarrays of size k in an array.

## STL Deque
- Dequeue implementation in c++ provides random access.

### How Its implemented internally
- Circular Array
- If the size exceed the capacity then we have to double the size of the array.
- We use array of pointers.
- Constant time as calling of the copy constructor.
- All operations is of the `O(1)`.

### Disadvantages
- Array of pointers if it full then it also doubled and copied.
