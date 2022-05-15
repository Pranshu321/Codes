#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int count_subset_sum_eqal_diff(int a[],int n,int sum){
    int dp[n+1][(sum+1)];
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=0;i<=sum;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j]=dp[i-1][j] + dp[i-1][j-a[i-1]];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,1,2,3};
	int n=4 , diff=1,arr_sum=0;
	for(int i=0;i<n;i++){
	    arr_sum+=a[i];
	}
	int sum= (arr_sum + diff) / 2; // (i) subset(2) - subset(1) = diff;
	                               // (ii) subset(2) + subset(1) = arr_sum; plus both equations.
	cout<<count_subset_sum_eqal_diff(a,n,sum);
	
	return 0;
}