#include <bits/stdc++.h>
using namespace std;
void check(int a[], int n)
{ const int m=1e6+2;
    bool b[m]; // boolean array
    for(int i=0;i<m;i++)
    { b[i]=false;}
    for(int i=0;i<n;i++)
    { if(a[i]>=0)
        b[a[i]]=true;
    }
    for(int i=0;i<m;i++)
    if(b[i]==false)
    {cout<<i;
    break;}
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i]; // checking smallest positive number missing in array
	check(a,n);
	
	return 0;
}
