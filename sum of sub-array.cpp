#include <bits/stdc++.h>
using namespace std;

int main() {
	// sum of the subarray of the array..
	int n,ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{ cin>>a[i];}
	for(int i=0;i<n;i++)
	{ ans=0;
	    for(int j=i;j<n;j++)
	   {ans+=a[j];
	       //cout<<a[j]<<"\n";
	       cout<<ans<<"\n";
	   }
	}
	return 0;
}
