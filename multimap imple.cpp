#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
multimap<int,int> mp;
	multimap<int,int> :: iterator itr;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	mp.insert(pair<int,int>(i,a));}
	for(itr=mp.begin();itr!=mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
	mp.insert(pair<int,int>  (0,45)); 
	mp.insert(pair<int,int>  (0,37)); cout<<endl;
	mp.erase(3);
	for(itr=mp.begin();itr!=mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
	return 0;
}
