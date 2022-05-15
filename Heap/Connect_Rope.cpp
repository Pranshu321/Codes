#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void Connect_Rope(int a[],int n){
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    int cost=0;
    while(pq.size()>=2){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        cost+=first+second; // adding smallest one's
    pq.push(first+second);
     }  // pushing the sum;
    cout<<cost<<" ";
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,2,3,4,5};
	int n=5;
	Connect_Rope(a,n);
	
	return 0;
}