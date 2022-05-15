#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n; cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
map<int,int>mp;
int Pre_sum=0; // for storing the sum;
for(int i=0;i<n;i++){
    Pre_sum+=a[i]; // adding the sub arrays
    mp[Pre_sum]++; // for Pre_sum as a key we ++;
}
int ans=0;
map<int,int>:: iterator itr;
for(itr=mp.begin();itr!=mp.end();itr++){
    int c=itr->second; // saving the frequency
    ans+=(c*(c-1))/2; // nC2 no. of combinations we are choosing the two elements between which the elemnts have zero;
    if(itr->first==0){
        ans+=itr->second; // if 0 add for prefix sum 0
    }
}
cout<<ans<<"\n";
	
	return 0;
}