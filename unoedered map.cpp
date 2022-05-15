#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	unordered_map<int,int> mp;
	unordered_map<int,int> :: iterator itr;
	int n; cin >> n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	    mp[i]=a;
	}
	for(itr=mp.begin();itr!=mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n"; 
      mp.erase(2); cout<<endl;
	for(itr=mp.begin();itr!=mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n"; 
	return 0;
}
