# Morris Traversal
It is the most optimize way to traverse the tree in the `O(1)` space complexity and time complexity of `O(N)`.

## Observation
1. Whenever we encounter to the leaf node or last node we have to come back to root node of tree or sub tree.

## Cases
1. 1st Case --> left=NULL
    - Then we have to print curr or root and move to right.

2. 2nd Case --> before moving left
    - We have to make a pointer from most right child of left subtree connected to the current after that curr=curr->left.

3. If There is thread in the last right leaf node of left subtree have the thread we remove that thread and move to as curr=curr->right.

![image](https://user-images.githubusercontent.com/86917304/175830793-50b5e277-8e1d-4a31-a6d0-a95bfeeb3ca3.png)