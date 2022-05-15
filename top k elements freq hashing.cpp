#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n; cin>>n;
int a[n];
int k; cin>>k;
for(int i=0;i<n;i++){
    cin>>a[i];
}
map<int,int>mp;
for(int i=0;i<n;i++){
    int pres=mp.size();
    if(mp[a[i]]==0 && pres==k){
        break;
    }
    mp[a[i]]++;
}
vector<pair<int,int>>ans;
map<int,int>:: iterator itr;
for(itr=mp.begin();itr!=mp.end();itr++){
    if(itr->second!=0){
        pair<int,int>p;
        p.first=itr->second;
        p.second=itr->first;
        
        ans.push_back(p);
    }
    
}
sort(ans.begin(),ans.end(),greater<pair<int,int>>());
vector<pair<int,int>>:: iterator vi;
for(vi=ans.begin();vi!=ans.end();vi++){
    cout<<vi->second<<" "<<vi->first<<"\n";
}
	
	return 0;
}