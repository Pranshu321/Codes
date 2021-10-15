#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int mcm(int a[],int i,int j){
    if(i>=j)
    return 0;
    int ans=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int temp_ans=mcm(a,i,k)+mcm(a,k+1,j)+(a[i-1]*a[j]*a[k]); // a[i-1]*a[j]*a[k] this will known as how many multiplication will take and we can find the minimum one
        ans=min(ans,temp_ans);
    }
    return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,2,3,4,3};
	int n=5;
	cout<<mcm(a,1,n-1); // in this we take i =1 because we take i=0 then i-1 will became invalid;
	
	return 0;
}