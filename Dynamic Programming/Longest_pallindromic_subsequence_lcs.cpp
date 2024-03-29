#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string longest_common_pallindromic_subse(string a,string b,int n,int m){
    int dp[n+1][m+1];
    //b = reverse(a.begin(),a.end());
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans=ans+a[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(ans.begin() , ans.end());
    return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s,s1;
	cin>>s;
	s1=s;
	reverse(s1.begin(),s1.end());
	
	// in string we have to send the reverse of the entered string.....
	int n,m;
	n=m=s.length();
	cout<<longest_common_pallindromic_subse(s,s1,n,m);
	
	return 0;
}