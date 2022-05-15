#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool compare(pair<int,int>p1,pair<int,int>p2){
    double v1= (double)p1.first/p1.second; // val by weight 1st
    double v2= (double)p2.first/p2.second; // val by weight 2nd
    return v1>v2;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n; cin>>n;
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++){
	    cin>>v[i].first>>v[i].second;
	}
	int w; cin>>w;
	sort(v.begin(),v.end(),compare);
	int ans=0;
	for(int i=0;i<n;i++){
	    if(w>v[i].second){
	        ans+=v[i].first;
	        w-=v[i].second;
	        continue;
	    }
	    double vw= (double)v[i].first/v[i].second; // val by weight for each 
	    ans+=vw*w;
	    w=0;
	    break;
	}
	cout<<ans<<"\n";
	return 0;
}