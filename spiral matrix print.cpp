#include <bits/stdc++.h>
using namespace std;

int main() {
	// spiral matrix printing
	int n,m; cin>>n>>m;
	int a[n][m];
	for(int i=0;i<n;i++)
	{ for(int j=0;j<m;j++)
	    { cin>>a[i][j];}
	}
	int row_start=0,row_end=n-1,col_start=0,col_end=m-1;
	while(row_start<=row_end && col_start<=col_end)
	{
	    for(int i=col_start;i<=col_end;i++) //first row print
	{ cout<<a[row_start][i]<<" ";}
	row_start++;
	cout<<"\n";
	for(int i=row_start;i<=row_end;i++) //last column print
	{ cout<<a[i][col_end]<<" ";}
	col_end--;
	cout<<"\n";
	for(int i=col_end;i>=col_start;i--) // last row print
	{ cout<<a[row_end][i]<<" ";}
	row_end--;
	cout<<"\n";
	for(int i=row_end;i>=row_start;i--) // first column print
	{ cout<<a[i][col_start]<<" ";}
	col_start++;
	
	   
	}
	return 0;
}
