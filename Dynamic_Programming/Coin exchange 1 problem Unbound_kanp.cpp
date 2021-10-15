#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Coin_exchange(int coin[],int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(coin[i-1]<=j){
                dp[i][j]= dp[i][j-coin[i-1]] + dp[i-1][j];
            }
            else{
                dp[i][j]= dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int coin[]={1,2,3};
	int sum=4;
	cout<<Coin_exchange(coin,3,sum);
	
	return 0;
}