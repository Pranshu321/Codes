#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Longest_substring(string s,string s1,int n,int m){
    int dp[n+1][m+1],result=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(s[i-1]==s1[j-1]){
            dp[i][j]=dp[i-1][j-1]+1;
                result = max(dp[i][j],result);
            }
            else
            dp[i][j]=0;
        }
    }
    return result;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s,s1;
	cin>>s>>s1;
	int n=s.length();
	int m=s1.length();
	cout<<Longest_substring(s,s1,n,m);
	
	return 0;
}