#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	// stl used permutation
	ios::sync_with_stdio(0);
	int n; cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	v.push_back(a);
	    }
	    sort(v.begin(),v.end());
	    vector<vector<int>> ans;
	    do{
	        ans.push_back(v);
	    }while(next_permutation(v.begin(),v.end()));
	    
	    for(auto v:ans){ // means ans vector is stored in a 2d vector res
	        for(auto i:v)
	        cout<<i<<" ";
	        cout<<"\n";
	    }
	return 0;
}
