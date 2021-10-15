#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int unbounded_Knapsack(int a[],int wt[],int n,int W){
int dp[n+1][W+1];
for(int i=0;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(wt[i-1]<=j){
                dp[i][j]= max((a[i-1]+ dp[i][j-wt[i-1]]),dp[i-1][j]); // single changes from knapsack that in first term from i-1 we put i because we can take our fav as many times we want.
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][W];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	 int a[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50,n=3;
	cout<<unbounded_Knapsack(a,wt,n,W);
	
	return 0;
}