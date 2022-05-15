#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	list<int>li;
	list<int>:: iterator itr;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	    li.push_back(a);
	}
	for(itr=li.begin();itr!=li.end();itr++)
	cout <<(*itr)<< endl;
	/*li.remove(44) ;  cout<<endl;
	for(itr=li.begin();itr!=li.end();itr++)
	cout <<(*itr)<< endl;*/
		itr++; 
		li.insert(itr,55); cout<<"\n";
		for(itr=li.begin();itr!=li.end();itr++)
	cout <<(*itr)<< endl;
	return 0;
}
