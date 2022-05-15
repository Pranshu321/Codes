#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n; cin>>n;
vector<pair<int,int>>v;
for(int i=0;i<n;i++){
    int start,end;
    cin>>start>>end;
    v.push_back({end,start});
}
sort(v.begin(),v.end(),greater<pair<int,int>>());
int take=1;
int end_to_take=v[0].first;
for(int i=1;i<n;i++){
    if(v[i].second<end_to_take){
        take++;
        end_to_take=v[i].first;
    }
}
cout<<take<<"\n";
	
	return 0;
}