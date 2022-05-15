#include <bits/stdc++.h>
using namespace std;
bool issafe(int** arr,int x,int y,int n)
{ for(int row=0;row<x;row++) // we dont have check for full row as no queen will be placed after the one queue,
    { if(arr[row][y]==1)
        return false;
    }
    int row=x;
    int col=y;
    while(row>=0 && col>=0) // checking left daigonal
    { if(arr[row][col]==1)
        return false;
        row--;
        col--;
    }
    row=x; col=y;
    while(row>=0 && col<n) // checking right daigonal
    { if(arr[row][col]==1)
        return false;
        row--;
        col++;
    }
    return true;
}
bool queen_place(int** arr,int x,int n)
{ if(x>=n)
return true;
    for(int col=0;col<n;col++){
    if(issafe(arr,x,col,n)){
       arr[x][col]=1;
        if(queen_place(arr,x+1,n))
        return true;
        arr[x][col]=0; //backtracking
    }
}
return false;}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n; cin>>n;
	int** arr= new int*[n];
	for(int i=0;i<n;i++){
	arr[i]=new int[n];
	for(int j=0;j<n;j++)
	{ arr[i][j]=0;}
	}
	if(queen_place(arr,0,n))
	{ for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++)
	    { cout<<arr[i][j]<<" ";}
	cout<<"\n";}
	    
	}
	
	return 0;
}
