#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1000][1000];
int mcm_memorisation(int a[],int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i+1;k<=j;k++){
        dp[i][j]=min(dp[i][j],mcm_memorisation(a,i,k-1)+mcm_memorisation(a,k,j)+(a[i-1]*a[k]*a[j-1])); // i-1 because we make index start from 1 and j is because we have to consider the last element also.
    }
    return dp[i][j];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	memset(dp,-1,sizeof(dp)); // new function
	int a[]={1,2,3,4,3};
	int n=5;
	cout<<mcm_memorisation(a,1,n-1);
	
	return 0;
}