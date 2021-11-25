#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define N 10002
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n,m; cin>>n>>m;
vector<int>v[N]; // vector of array
for(int i=0;i<m;i++){
    int x,y; cin>>x>>y;
    v[x].push_back(y); // saving the edges link between nodes
    v[y].push_back(x);
}
vector<int>::iterator it;
cout<<"Adajency list for above graph is \n";
for(int i=1;i<n+1;i++){
    cout<<i<<" -> ";
    for(it=v[i].begin();it!=v[i].end();it++){
        cout<<*(it)<<" ";
        
    }
    cout<<endl;
}
	
	return 0;
}