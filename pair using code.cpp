#include <bits/stdc++.h>
using namespace std;
bool comparitor(pair<int,int>v1,pair<int,int>v2){
	        return v1.first<v2.first;
	    }
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int arr[]={10,16,7,14,5,3,12,9};
	vector<pair<int,int>> v;
	for(int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++)
	{ v.push_back(make_pair(arr[i],i)); // it store the nummber and position of number
	    }
	    sort(v.begin(),v.end(),comparitor);
	    for(int i=0;i<v.size();i++)
	    {arr[v[i].second]=i;} // in this in the at the position saved in array we store that positions and give them new i positions.
	    
	    for(int i=0;i<v.size();i++)
	    cout<<arr[i]<<" ";
	return 0;
}
