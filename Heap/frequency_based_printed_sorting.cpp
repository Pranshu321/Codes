#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int a[]={1,1,1,3,2,2,4};	
	int k=2,n=7;
	unordered_map<int,int>mp;
    priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
	for(int i=0;i<n;i++){
		mp[a[i]]++;
	}
	for(auto i:mp){
		pq.push({i.second,i.first});
	}
	while(!pq.empty()){
		int ele=pq.top().second;
		int freq=pq.top().first;
		cout<<ele<<" "<<freq<<"\n";
		pq.pop();
	}

	return 0;
}