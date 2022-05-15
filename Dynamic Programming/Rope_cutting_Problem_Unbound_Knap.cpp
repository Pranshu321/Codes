#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Rope_Cutting(int price[],int len[],int n,int max_len){
int dp[n+1][max_len+1];
for(int i=0;i<=n;i++){
        for(int j=0;j<=max_len;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(len[i-1]<=j){
                dp[i][j]= max((price[i-1]+ dp[i][j-len[i-1]]),dp[i-1][j]); // single changes from knapsack that in first term from i-1 we put i because we can take our fav as many times we want.
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][max_len];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	 int length[] = { 1  , 2  , 3 ,  4  , 5 , 6 , 7 ,8};
    int price[] = { 1  , 5  , 8  , 9,  10 , 17 , 17 , 20};
    int max_len=8,n=8;
	cout<<Rope_Cutting(price,length,n,max_len);
	
	return 0;
}