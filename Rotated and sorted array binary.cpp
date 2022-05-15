#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int idxRotatedArray(int a[],int key,int start,int end){
    if(start>end){
        return -1;
    }
    int mid=(start+end)/2;
    if(a[mid]==key){
        return mid;
    }
    if(a[start]<=a[mid]){
        if(key>=a[start] && key<=a[mid]){
            return idxRotatedArray(a,key,start,mid-1);
        }
            return idxRotatedArray(a,key,mid+1,end);
        
    }
    if(key>=a[mid] && key<=a[end]){
        return idxRotatedArray(a,key,mid+1,end);
    }
    return idxRotatedArray(a,key,start,mid-1);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={6,7,8,9,10,1,2,3};
	int n=8,m=2;
	int idx=idxRotatedArray(a,m,0,n-1);
	if(idx==-1)
	cout<<"does not exist";
	else
	cout<<"Key exist on index :- "<<idx;
	
	
	return 0;
}