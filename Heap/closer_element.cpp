#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void Closet_Elements(int a[],int n,int x,int k){
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<n;i++){
        pq.push({abs(x-a[i]),a[i]}); // saving the key and diffrence of the all elements with x value.
        if(pq.size()>k){
            pq.pop();
        }
    }
    while(!pq.empty()){
        cout<<pq.top().second<<" ";
        pq.pop();
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={6,7,5,9,8};
	int x=7,k=3,n=5;
	Closet_Elements(a,n,x,k);
	return 0;
}