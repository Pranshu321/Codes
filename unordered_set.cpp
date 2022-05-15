#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	unordered_set<string> s;
	unordered_set<string>:: iterator itr;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{ string a; cin>>a;
	    s.insert(a);
	}
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<"\n";
		s.erase("simran"); 
		s.insert("jain"); cout<<endl;
		//s.clear();
		for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<"\n";
	return 0;
}
