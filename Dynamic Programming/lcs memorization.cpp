#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[1001][1001];
int Longest_Subsequence_memorization(string s,string s1,int n,int m){
    if(n==0 || m==0)
    return 0;
    if(dp[n][m]!=-1)
    return dp[n][m];
    if(s[n-1]==s1[m-1]){
        return dp[n][m]=(1+Longest_Subsequence_memorization(s,s1,n-1,m-1));
    } // 1+ because we found one element of subsequence which is equal in both string
    else{
        return dp[n][m]=max(Longest_Subsequence_memorization(s,s1,n,m-1),Longest_Subsequence_memorization(s,s1,n-1,m));
    } // whenever there is longest,greatest,bada we use max,
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s,s1;
	cin>>s>>s1;
	int n=s.length(),m=s1.length();
	for(int i=0;i<1001;i++){
	    for(int j=0;j<1001;j++){
	        dp[i][j]=-1;
	    }
	}
	cout<<Longest_Subsequence_memorization(s,s1,n,m);
	
	return 0;
}