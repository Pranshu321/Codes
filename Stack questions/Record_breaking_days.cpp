#include <bits/stdc++.h>
using namespace std;

int main() {
	// record breaking days question google kick start
	int n; cin>>n;
	int a[n+1]; // because we have to also check the last element of the array
	a[n]=-1;    // -1 because it is always false so not include in our answer
	for(int i=0;i<n;i++)
	{ cin>>a[i];
	    
	}
	if(n==1)
	{ cout<<'1'<<"\n"; // single day always be maximun itself
	    return 0;
	}
	int ans=0;
	int mx=INT_MIN;
	for(int i=0;i<n;i++)
	{ if(a[i]>mx && a[i]>a[i+1]) // checking if the day is greater than max and 
	// also greater than the next element in array...:)
	 ans++;
	 mx=max(mx,a[i]);
	
	}
	cout<<ans;
	return 0;
}
