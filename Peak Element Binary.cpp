#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int Find_Peak_Element(int a[],int low,int high,int n){
    int mid=(low+high)/2;
    if(mid==0||a[mid-1]<=a[mid] && (mid==n-1||a[mid+1]<=a[mid])){
        return mid;
    }
    else if(mid>0 && a[mid-1]>a[mid]){
        return Find_Peak_Element(a,low,mid-1,n);
    }
    else{
        return Find_Peak_Element(a,mid+1,high,n);
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={0,6,8,5,7,9};
	cout<<Find_Peak_Element(a,0,5,6);
	
	return 0;
}