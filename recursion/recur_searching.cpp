#include <bits/stdc++.h>
using namespace std;
int first(int a[],int n,int i,int key)
{ if(i==n)
  return -1;
  if(a[i]==key)
  return i;
  first(a,n,i+1,key);
    
}
// int second(int a[], int n,int i,int key)
// { int last= second(a,n,i+1,key);
//     if(last!=-1)
//     return last;
//     if(a[i]==key)
//     return i;
//     return -1;
// }
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int n,key;
	cin>>n>>key;
	int a[n];
	for(int i=0;i<n;i++)
	{ cin>>a[i];}
	cout<<first(a,n,0,key)<<endl;
	// cout<<second(a,n,0,key);
	return 0;
}
