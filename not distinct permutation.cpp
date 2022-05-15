#include <bits/stdc++.h>
using namespace std;
void helper(vector<int> &a, vector<vector<int>> &ans,int idx)
{ if(idx==a.size())
    { ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++)
    { if(i!=idx && a[i]==a[idx])
        continue; //  except swap
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }
}
vector<vector<int>> permutatuions(vector<int> v)
{ sort(v.begin(),v.end());
    vector<vector<int>> ans;
    helper(v,ans,0);
    return ans;
    
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
	    vector<vector<int>> res=permutatuions(v);
	    for(auto v:res){ // means ans vector is stored in a 2d vector res
	        for(auto i:v)
	        cout<<i<<" ";
	        cout<<"\n";
	    }
	return 0;
}
