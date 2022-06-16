#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void Sort(int a[],int n){
    if(n==1)
    return;
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1])
        swap(a[i],a[i+1]);
        Sort(a,n-1);
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={2,1,4,6,5,9};
	Sort(a,6);
	for(auto i:a)
	cout<<i<<" ";
	
	
	return 0;
}