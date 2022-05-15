#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{ int ans=1;
    for(int i=n;i>0;i--)
    { ans*=i;}
    return ans;
}
int main() {
	// your code goes here
	int n,r;
	cin>>n>>r;
	cout<<fact(n)/(fact(r)*fact(n-r));
	return 0;
}
