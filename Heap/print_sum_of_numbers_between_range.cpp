#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int KSmallest(int a[],int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
        if(pq.size()>k){
            pq.pop();
        }
    }
    return pq.top();
}

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,3,5,11,12,15};
	int n=6,k=3,k1=6,sum=0;
	for(int i=0;i<n;i++){
	if(a[i]>KSmallest(a,n,k) && a[i]<KSmallest(a,n,k1))
	sum+=a[i];
	}
	cout<<sum;
	return 0;
}