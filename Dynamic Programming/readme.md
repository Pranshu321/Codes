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

## Types of DP

### Top Down
When we work from big picture to small pictures , when we have complete understanding of the question , it is useful when we have sufficient knowledeged about problem , it is method in which solve components and combine them to derive solution.

- Example#1
**Fabonacci Series**
memorization + recursion = Top Down Dp.
`f(4) --> f(3) --> f(2) --> f(1).`

### Bottom Up
We also cache the results store in dp or array.
When we use bottom we find all possible cases but in top down we only find essential cases.
`f(1) --> f(2) --> f(3) --> f(4)`

- Forward DP
When we know some of the results and using that values we find the solution of others.

![image](https://user-images.githubusercontent.com/86917304/190857265-87302abd-51e8-42ee-a8e2-36bd0f7bddde.png)

- Backward DP
We know only the result of one sub problem and find others solutions.

![image](https://user-images.githubusercontent.com/86917304/190857309-bd454b4a-979a-482c-937b-ba3c062c79c5.png)

### Types of DP (Code)

- Simple Recursion
```cpp
void fibo{
    if(n==0){
        return 0;
    }
    if(n<=2){
        return 1;
    }
    
    return fibo(n-1) + fibo(n-2);
}
```
- Top Down
```cpp
int fibo(int n , vector<int>&dp){
    if(n==0){
        return 0;
    }
    if(n<=2){
        return 1;
    }
    if(dp[n]>0){
        return dp[n];
    }
    dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n];
}
int main() {
	// your code goes here
	int n; cin>>n;
	vector<int>dp(1000,0);
	cout<<"Answer"<<" "<<fibo(n,dp);
	return 0;
}
```

- Bottom up (Forward DP)

```cpp
	int n; cin>>n; 
	vector<int>dp(n+1 , 0);
	if(n==0){
	   cout<<0;
	   return 0;
	}
	if(n<=2){
	    cout<<1;
	    return 0;
	}
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i=2; i<=n;i++){
	    dp[i]=dp[i-1]+dp[i-2];
	}
	
	cout<<dp[n];
```

- Bottom DP (Backward DP)

```cpp
	int n; cin>>n; 
	vector<int>dp(n+2 , 0); // As we take two module to compute answer
	if(n==0){
	   cout<<0;
	   return 0;
	}
	if(n<=2){
	    cout<<1;
	    return 0;
	}
	dp[0] = 0;
	dp[1] = 1;
	
	for(int i=1; i<n;i++){
	   dp[i+1]+=dp[i]; // here dp[i] already solved and can solved using find the solutions for others.
	   dp[i+2]+=dp[i];
	}
	
	cout<<dp[n];
```







