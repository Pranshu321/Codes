#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,e;
	cin>>n>>e;
	vector<int> v[n+1]  ;
	for(int i=0;i<e;i++)
	{int a,b;
	cin>>a>>b;
	v[a].push_back(b);
	v[b].push_back(a);}
	
	for(int i=1;i<n;i++)
	{ cout<<i<<"-> ";
	    for(auto j: v[i])
	    { cout<<j<<" ";}
	cout<<endl;}
	return 0;
}
