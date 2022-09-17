# Dynamic Programming
This is the way , in which we optimize the exponential time complexity to the variable time complexity or we say it bought down time complexity to power of n.

## Properties of Dynamic Programming
- Optimal Substructure :- This means that we design our algorithm or approach firstly for the small section of the problem and then drive it to general solution and a chain goes which eventually lead to our answer.

![image](https://user-images.githubusercontent.com/86917304/190854233-004d34ac-30bb-440a-860b-e95b63d217c5.png)

- Overlapping Subproblems :- This is the case when there calculation for a same problem again and again at different instances , so we can stop this by storing the result of that call and whenever we encounter that call we directly return the answer.

## Identification When we have to use DP?
- When there asking using **How many** and with optimization like **Minimum number of ways**.
- *maximum profit* this is identification that we have to use DP.

## Example#1

- ### _How many ways_ we can climb to top of stairs ? 
![image](https://user-images.githubusercontent.com/86917304/190854429-52d09e5b-f92b-4527-b3c0-7923a565663a.png)

1. First the edge cases or base cases
here we can se , 
- Reaching the second stairs we have two ways (directly to second stair , or 1st then second)
- F(0) = 1
- F(1) = 1

2. Recurence Relation
- F(n) = F(n-1) + F(n-2) , this is relation which we have derived using rules of sum , and here this means that we take 1 step (F(n-1)) or we can take 2 steps directly (F(n-2)).

3. Order of computation
The parameters on which our solution depends here (n-1 , n-2).

4. Location of Answer
Means at the end of question where we will get our solution.



