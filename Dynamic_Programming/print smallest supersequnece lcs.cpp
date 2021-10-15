#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int print_smallest_supersequence(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return m+n-dp[n][m]; // dono merge karne ke baad hamesha lcs is common rahega aur vo do baar aayega tho smallest nikalne ke liye hame usko minus karna hoga
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s,s1;
	cin>>s>>s1;
	int n=s.length();
	int m=s1.length();
cout<<print_smallest_subsequence(s,s1,n,m);
	
	
	return 0;
}