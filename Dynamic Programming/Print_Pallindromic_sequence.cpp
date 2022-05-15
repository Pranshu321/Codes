#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

string pallin_print(string a,string b,int n,int m){
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n,j=m;
    string ans;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans=ans+a[i-1];
            i--; j--;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        }
        else
        j--;
    }
    return ans;
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 string s;
 string s1;
 cin>>s;
 s1=s;
 reverse(s1.begin(),s1.end());
 int n,m=s.length();
 n=m;
 cout<<pallin_print(s,s1,n,m);
 
 
 
 
return 0 ;
 
 
 } 