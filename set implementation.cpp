#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	set<int >s ;
	set<int> :: iterator itr;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	    s.insert(a);
	}
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<endl;
	/*s.erase(44); cout<<endl;
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<endl;*/
	itr= s.upper_bound(22);
	auto ret = s.emplace(55);
	if(!ret.second)
	cout<<"66 already exist";
	cout<<"\n"<<(*itr)<<"\n";
	
	return 0;
}
