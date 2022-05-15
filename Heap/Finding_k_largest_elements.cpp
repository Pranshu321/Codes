#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
priority_queue<int,vector<int>,greater<int>>pq;
int a[]={7,10,4,3,20,15};
int n=6,k=3;
for(int i=0;i<n;i++){
    pq.push(a[i]);
    if(pq.size()>k){
        pq.pop();
    }
}
while(!pq.empty()){
cout<<pq.top()<<" ";
pq.pop();}
	return 0;
}