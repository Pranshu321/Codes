#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void DeleteMiddleElement(stack<int>&s,int k){
    if(k==1){
        s.pop();
        return;
    }
    int temp=s.top();
    s.pop();
    DeleteMiddleElement(s,k-1);
    s.push(temp);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,2,3,4,5};
	stack<int>s;
	for(int i=0;i<5;i++){
	    s.push(a[i]);
	}
	DeleteMiddleElement(s,3);
	while(!s.empty()){
	    cout<<s.top()<<" ";
	    s.pop();
	}
	
	return 0;
}