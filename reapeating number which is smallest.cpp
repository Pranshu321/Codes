#include <bits/stdc++.h>
using namespace std;

int main() {
	// smallest position repeating number array
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	const int N= 1e9+2;
	int idx[N]; // idx is the in which the position of a[i] is stored on the number 
	// in a[i] to the same position in idx array... 
	for(int i=0;i<N;i++)
	idx[i]= -1;
	int mini = INT_MAX;
	for(int i=0;i<n;i++)
	{ if(idx[a[i]]!= -1) 
	    { mini = min(mini,idx[a[i]]);} // minimum position
	    else
	    {idx[a[i]]=i;} // storing the position 
	}
	if(mini==INT_MAX)
	{ cout<<"-1"<<"\n";}
	else
	cout<<mini+1<<"\n";
	return 0;
}
