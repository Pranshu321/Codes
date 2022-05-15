#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	map<int,string> mp ;
	int n;
	string s;
	cin>>n;
	for(int i=5;i>0;i--)
	{ cin>>s;
	    mp[i]=s;
	}
	map<int,string>::iterator itr=mp.begin();
/*for(itr=mp.begin(); itr!= mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";*/
		
		mp.insert(pair<int,string>(6,"jain")); cout<<endl;
		
		for(itr=mp.begin(); itr!= mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
	itr=mp.find(4); 
	cout<<"\n"<<(*itr).second<<endl;
		for(itr=mp.begin(); itr!= mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
	return 0;
}
