#include <bits/stdc++.h>
using namespace std;
int knapsack(int v[],int w[],int n,int W)
{ if(n==0 || W==0)
    return 0;
    if(w[n-1]>W)
    return knapsack(v,w,n-1,W); //  it this we are considering but not putting in sack
    return (max(knapsack(v,w,n-1,W-w[n-1])+v[n-1],knapsack(v,w,n-1,W)));
}// in the first we are considering the elememt and adding in sack.
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	int w[]={10,20,30};
	int v[]={100,50,150};
	int W=50;
	cout<<knapsack(v,w,3,W);
	return 0;
}
