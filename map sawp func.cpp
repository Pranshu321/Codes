#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	vector<string>v{"pranshu","simran","rekha"} ;
	vector<string>v1{"bobby","deepak"};
	map<string,int>mp,mp1;
	map<string,int>:: iterator itr;
	for(int i=0;i<3;i++)
	{ int n; cin>>n;
	    mp[v[i]]=n;
	}
	for(int i=0;i<2;i++)
	{ int z; cin>>z;
	    mp1[v1[i]]=z;
	}
	mp.swap(mp1);
	cout<<"mp  contsins"<<"\n";
	for( itr=mp.begin();itr!=mp.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
		cout<<"mp 1 contsins"<<"\n";
	for( itr=mp1.begin();itr!=mp1.end();itr++)
	cout<<(*itr).first<<" "<<(*itr).second<<"\n";
	return 0;
}
