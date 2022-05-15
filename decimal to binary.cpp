#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n,a[10],x=0;
	cin>>n;
	for(int i=0;n>0;i++)
	{ x++;
	    a[i]=n%2;
	    n=n/2;
	}
	for(int i=x-1;i>=0;i--)
	{cout<<a[i];}
	return 0;
}
