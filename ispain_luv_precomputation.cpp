#include<bits/stdc++.h>
 
 using namespace std;
 const int N=1e7+10;
 #define ll long long int
 int hsh[N][26];
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int t; cin>>t;
 while(t--){
     int n,q; cin>>n>>q;
     string s;
     cin>>s;
     for(int i=0;i<n;i++){
         hsh[i+1][s[i]-'a']++;
     }
     for(int i=0;i<26;i++){
         for(int j=1;j<=n;j++){
             hsh[j][i]+=hsh[j-1][i];
         }
     }
     while(q--){
         int l,r; cin>>l>>r;
         int odd=0;
         for(int i=0;i<26;i++){
             int count=hsh[r][i]-hsh[l-1][i];
             if(count%2!=0)
             odd++;
         }
         if(odd>1)
         cout<<"NO\n";
         else
         cout<<"YES\n";
     }
 }
 
 
 
 
return 0 ;
 
 
 } 