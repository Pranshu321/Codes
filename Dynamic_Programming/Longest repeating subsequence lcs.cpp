#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int longest_repeating_subsequence(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1] && i!=j){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s;
	cin>>s;
	int n=s.length();
	cout<<longest_repeating_subsequence(s,s,n,n);
	
	return 0;
}