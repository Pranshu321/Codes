#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isfeasible(int a[],int n,int m,int mid){
    int sum=0,painters=1;
    for(int i=0;i<n;i++){
        if(a[i]>mid)
        return false;
        if(sum+a[i]>mid){
            painters++;
            sum=a[i];
        }
        if(painters>m)
        return false;
        else{
            sum+=a[i];
        }
    }
    return true;
}
int painterspartitonpronlem(int a[],int n,int m){
    if(n<m){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    sum+=a[i];
    int start=0,end=sum,ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(isfeasible(a,n,m,mid)){
            ans=min(ans,mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }
    return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={10,20,30,40};
	int n=4,m=2;
	cout<<painterspartitonpronlem(a,n,m);
	
	return 0;
}