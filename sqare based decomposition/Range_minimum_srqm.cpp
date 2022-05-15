#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++)
cin>>a[i];
int len= (int)sqrtl(n)+1;
vector<int>b(n,INT_MAX);
for(int i=0;i<n;i++){
    b[i/len]=min(a[i],b[i/len]);
}
int ans=INT_FAST8_MAX;
int q; cin>>q;
while(q--){
    int l,r;
cin>>l>>r;
for(int i=l;i<=r;){
    if(i%len==0 && i+len-1<=r){
      ans=min(ans,b[i/len]);
      i+=len;
    }
    else{
        ans=min(ans,a[i]);
        i++;
    }
}
cout<<ans<<"\n";
}
 
 
 
return 0 ;

} 