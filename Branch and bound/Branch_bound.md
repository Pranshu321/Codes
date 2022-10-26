# Branch & Bound

Branch and bound is an algorithm design paradigm which is generally used for solving **combinatorial optimization problems**. These problems are typically exponential in terms(In power of 2) of time complexity and may require exploring `all possible permutations in worst case`. The Branch and Bound Algorithm technique solves these problems relatively quickly.

- Branch and bound is BFS and our backtracking is DFS.

![image](https://user-images.githubusercontent.com/86917304/174141367-6916d461-a26e-493b-86ae-7f7b024afa9f.png)

## Lets understand with example

As we know in backtracking all the possible paths is covered and it can be optimized if we know that the bound on best possible solution subtree rooted with every node. If the **best in subtree is worse than current best**, we can simply ignore this node and its subtrees. So we compute bound (best solution) for every node and compare the bound with current best solution before exploring the node.

## Three types of branch and bound

![image](https://user-images.githubusercontent.com/86917304/174238180-60043fcc-8aea-4962-ab0a-2888a45f9bde.png)

1. Using Stack (In this we start expanding with last node with C-30)
2. Using Queue (In this we start expanding with first node with C-25)
3. Using Least-Cost Branch & Bound `LC-BB` (In this we start expanding with the node having least cost here it is C-12)

## Some problems

- [Branch and Bound | Set 1 (Introduction with 0/1 Knapsack)](https://www.geeksforgeeks.org/branch-and-bound-set-1-introduction-with-01-knapsack/)
- [Branch and Bound | Set 2 (Implementation of 0/1 Knapsack)](https://www.geeksforgeeks.org/branch-and-bound-set-2-implementation-of-01-knapsack/)
- [Branch and Bound | Set 3 (8 puzzle Problem)](https://www.geeksforgeeks.org/branch-bound-set-3-8-puzzle-problem/)
- [Branch And Bound | Set 4 (Job Assignment Problem)](https://www.geeksforgeeks.org/branch-bound-set-4-job-assignment-problem/)
- [Branch and Bound | Set 5 (N Queen Problem)](https://www.geeksforgeeks.org/branch-and-bound-set-4-n-queen-problem/)
- [Branch And Bound | Set 6 (Traveling Salesman Problem)](https://www.geeksforgeeks.org/branch-bound-set-5-traveling-salesman-problem/)
