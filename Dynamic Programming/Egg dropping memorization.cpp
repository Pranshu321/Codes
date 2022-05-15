#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// no. of attempts for egg dropping in worst case
int dp[1001][1001];
int Egg_dropping(int e,int f){
if(f==0 || f==1)
return f;
if(e==1)
return f;
if(dp[e][f]!=-1){
    return dp[e][f];
}
int ans=INT_MAX;
for(int k=1;k<=f;k++){
    int temp=1+max(Egg_dropping(e-1,k-1),Egg_dropping(e,f-k)); // 1 for the attempt and we use max for selecting the worst condition .
    ans=min(ans,temp);
}
dp[e][f]=ans;
return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int e=3,f=5;
	memset(dp,-1,sizeof(dp));
	cout<<Egg_dropping(e,f);
	
	return 0;
}