#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>ans; // globally declared 2d array
void permutatuions(vector<int> &a, int idx){
    if(idx==a.size())
    { ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    { swap(a[i],a[idx]); // swap the numbers 3 first from srartng
        permutatuions(a,idx+1);
        swap(a[i],a[idx]); // swap from last 
    }
    return;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n; cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	v.push_back(a);
	}
	    permutatuions(v,0);
		cout<<"----------- PERMUTATIONS ------------\n";
	    for(auto v:ans){ // means ans vector is a 2d vector
	        for(auto i:v)
	        cout<<i<<" ";
	        cout<<"\n";
	    }
	return 0;
}
