#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Find_min(int a[],int n,int sum){
    bool dp[n+1][sum+1];
    for(int i=0;i<=sum;i++){ // from here we start subset equal to sum
        dp[0][i]=false;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(a[i-1]<=j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            if(j<a[i-1])
            dp[i][j]=dp[i-1][j];
        }
    }
    int diff=INT_MAX;
    for(int j=sum/2;j>=0;j--){ // start from sum/2 
        if(dp[n][j]){  // we are taking the last row that have the array which will have full array as set and which represent as the set s1 and second range - s1;
            diff= sum - (2*j);
            break;
        }
    }
    return diff;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,2,7};
	int n=3,sum=10;
	cout<<Find_min(a,n,sum);
	
	return 0;
}