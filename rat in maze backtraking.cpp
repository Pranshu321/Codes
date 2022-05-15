#include <bits/stdc++.h>
using namespace std;
bool issafe(int** arr,int x,int y,int n) //this tells is path is block or open
{ if(x<n && y<n && arr[x][y]==1)
    {return true;
        
    }
    return false;
}
bool ratinmaze(int** arr, int x,int y,int n, int** solarr)
{ if(x==n-1 && y==n-1)
   { solarr[x][y]=1;
       return true;
   }
    if(issafe(arr,x,y,n))
    { solarr[x][y]=1;
    if(ratinmaze(arr,x+1,y,n,solarr)) // checking if the by moving hori forward is solution or not
    {return true;}
    if(ratinmaze(arr,x,y+1,n,solarr))  // checking if the by moving verticle forward is solution or not
    {return true;}
    solarr[x][y]=0; //this is called backtraking means we are correcting our mistake
    return false;
    }
    return false;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n; cin>>n;
	int** arr= new int*[n]; // 2d dynamic alocaion
	for(int i=0;i<n;i++)
	arr[i]= new int[n];
	for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++)
	    cin>>arr[i][j];
	}
	int** solarr= new int*[n];
	for(int i=0;i<n;i++){
	solarr[i]= new int[n];
      for(int j=0;j<n;j++)
	    {solarr[i][j]=0;}
	}
	if(ratinmaze(arr,0,0,n,solarr))
	{for(int i=0;i<n;i++)
	{ for(int j=0;j<n;j++)
	    cout<<solarr[i][j]<<" ";
	 cout<<"\n";}
	}
	
	
	return 0;
}
