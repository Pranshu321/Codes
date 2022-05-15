#include <bits/stdc++.h>
using namespace std;
// in this the 2d array is sorted in row wise and col wise both
int main() {
	// matrix search by efficient method
	int n,m,ele;
	cin>>n>>m>>ele;
	int m1[n][m];
	for(int i=0;i<n;i++)
	{ for(int j=0;j<m;j++)
	    { cin>>m1[i][j];}
	}
	int r=0,c=m-1;
	bool flag= false;
	while(r<n && c>=0)
	{ if(m1[r][c]==ele)
	    {flag=true;}
	    if(m1[r][c]>ele)
	    { c--;}
	    else
	    { r++;}
	}
	if(flag)
	cout<<"element found";
	else
	cout<<"element not found";
	return 0;
}
