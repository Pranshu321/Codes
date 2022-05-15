#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n; cin>>n;
	int target; cin>>target;
	vector<int>v(n);
	for(auto &i:v)
	cin>>i;
	bool found=false;
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
	    int lo=i+1; int hi=n-1;
	    while(lo<hi){
	        int current=v[i]+v[lo]+v[hi];
	        if(current==target)
	        found=true;
	        if(current<target)
	        lo++;
	        else
	        hi--;
	    }
	    }
	    if(found)
	    cout<<"true";
	    else
	    cout<<"false";
	
	return 0;
}
