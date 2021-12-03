#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void MinimunSubArrayWithSum(int a[],int n,int x){
    int sum=0,minlength=n+1,start=0,end=0;
    while(end<n){ // if end less than n;
        while(sum<=x && end<n){  // when sum less thn x and end also less than n
            sum+=a[end++];
        }
        while(sum>x && start<n){   // when sum greater than x and start less than n;
            if(end-start<minlength){  // when end-start less than minlength 
                minlength=end-start;
            }
            sum-=a[start++];  // changing the window
        }
    }
    cout<<minlength;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={1,4,45,6,10,19};
	int x=51;
	int n=6;
	MinimunSubArrayWithSum(a,n,x);
	
	return 0;
}