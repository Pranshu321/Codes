#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here 
	multiset<int> s;
	multiset<int >:: iterator itr;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	    s.insert(a);
	    
	}
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<"\n";
	/*itr=s.begin();
	itr++;
	s.insert(45); cout<<endl;
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<"\n";*/
	s.erase(89); cout<<endl;
	for(itr=s.begin();itr!=s.end();itr++)
	cout<<(*itr)<<"\n";
	
	return 0;
}
