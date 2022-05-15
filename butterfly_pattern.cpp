#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{ for(int j=1;j<=i;j++)
	    cout<<"*";
	
	int space=2*n-2*i;
	for(int j=1;j<=space;j++)
	cout<<" ";
	 for(int j=1;j<=i;j++)
	    cout<<"*";
	    cout<<"\n";
	}
	for(int i=n;i>=1;i--)
	{ for(int j=1;j<=i;j++)
	    cout<<"*";
	
	int space=2*n-2*i;
	for(int j=1;j<=space;j++)
	cout<<" ";
	 for(int j=1;j<=i;j++)
	    cout<<"*";
	    cout<<"\n";
	}
	    
	return 0;
}
