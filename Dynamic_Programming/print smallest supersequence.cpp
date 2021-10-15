#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void print_smallest_supersequence(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
            dp[i][j]=0;
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j-1],dp[i-1][j-1]);
        }
    }
    int i=n,j=m;
    string s="";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            s=s+a[i-1];
            i--; j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            s=s+b[j-1];
            j--;
        }
        else{
            s=s+a[i-1];
            i--;
        }
    }
    while(i>0){
        s=s+a[i-1];
        i--;
    }
    while(j>0){
        s=s+b[j-1];
        j--;
    }
    reverse(s.begin(),s.end());
    cout<<s;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string a,b;
	cin>>a>>b;
	int n=a.length(),m=b.length();
	print_smallest_subsequence(a,b,n,m);
	
	return 0;
}