#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n,k; cin>>n>>k;
	vector<int>a(n);
	for(auto &i:a){
	cin>>i;
	}
	int zerocent=0,i=0,ans=0;
	
	for(int j=0;j<n;j++){
	    if(a[j]==0)
	    zerocent++;
	    while(zerocent>k)
	    { if(a[i]==0){
	        zerocent--;}
	        i++;
	    }
	    ans=max(ans,j-i+1);
	}
	cout<<ans<<"\n";
	
	return 0;
}
