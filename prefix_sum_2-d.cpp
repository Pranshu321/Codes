#include<bits/stdc++.h>
 
 using namespace std;

 const int N=10000;
 #define ll long long int
 ll pf[N][N];
//  ll ar[N][N];
 int main () 
{  ll sum=0;
   int n; cin>>n;
   int ar[n][n];
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0); 
 for(int i=1;i<=n;i++){
     for(int j=1;j<=n;j++){
         cin>>ar[i][j];
         pf[i][j] = ar[i][j] + pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1];
     }
 }
 int a,b,c,d;
 cin>>a>>b>>c>>d;
 cout<< pf[c][d] - pf[a-1][d] - pf[c][b-1] + pf[a-1][b-1];
 
 
 
return 0 ;
 
 
} 