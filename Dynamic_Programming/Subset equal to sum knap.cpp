#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool subset(int a[],int n,int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j)
            dp[i][j]= dp[i - 1][j] || dp[i - 1][j - a[i - 1]] ;
            
             if (j < a[i - 1])
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={2,3,7,8,10};
	int sum=11;
	int n=5;
	if( subset(a,n,sum)==true)
	cout<<"yipppeeee";
	else
	cout<<"hat bsdk";
	
	return 0;
}