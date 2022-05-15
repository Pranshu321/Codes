#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,dec=0,ans=0,b=1;
	cin>>n;
	while(n>0)
	{ ans= n%10;
	dec=dec+ ans*b;
	b*=2;
	n/=10;
	    }
	    cout<<dec;
	return 0;
}
