#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void nearest_left_smallest_element(int a[],int n){
    stack<int>s;
    int res[n];
    for(int i=0;i<n;i++){
        while(!s.empty() && s.top()>=a[i]){
            s.pop();
        }
        res[i]=s.empty()?-1:s.top();
        s.push(a[i]);
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
	    cin>>a[i];
	}
	nearest_left_smallest_element(a,n);
	return 0;
}
