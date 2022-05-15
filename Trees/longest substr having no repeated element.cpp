#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s; cin>>s;
	vector<int>v(256,-1);
	int x=0;
	int ans=0,maxlen=0,start=0;
	for(int i=0;i<s.length();i++){
	    if(v[s[i]]>start){
	        start=v[s[i]];
	    }
	    v[s[i]]=i;
	    x=start;
	    ans=max(ans,i-start);
	}
	cout<<ans<<"\n";
	string c=s.substr(x,ans);
	cout<<c;
	return 0;
}
