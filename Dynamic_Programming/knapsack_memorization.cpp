#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int kanprec(int **dp,int val[],int wt[],int W,int i){
    if(i<0)
    return 0;
    if(dp[i][W]!=-1)
    return dp[i][W];
    
    if(wt[i]>W){
        dp[i][W]= kanprec(dp,val,wt,W,i-1);
        return dp[i][W];
    }
    else{
        dp[i][W]= max((val[i]+kanprec(dp,val,wt,W-wt[i],i-1)),kanprec(dp,val,wt,W,i-1));
        return dp[i][W];
    }
}
int knapsack(int val[],int wt[],int W,int n){
    int **dp;
    dp=new int*[n];
    for(int i=0;i<n;i++)
    dp[i]=new int[W+1];;
    for(int i=0;i<n;i++){
        for(int j=0;j<W+1;j++){
            dp[i][j]=-1;
        }
    }
    return kanprec(dp,val,wt,W,n-1);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int wt[]= {10,20,30};
	int val[]= {60,100,120};
	int W=50;
	int n=3;
	cout<<knapsack(val,wt,W,n);
	
	return 0;
}