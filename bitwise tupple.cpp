#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod= 1000000007;
int answer(int n,int m)
{ int a=1;
    while(m>0)
    { if(m&1)
        a=(a*n)%mod;
        n=(n*n)%mod;
        m=m>>1;
    }
    return a;
}
int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{ int n,m,num=0;
	    cin>>n>>m;
	    num= answer(2,n)-1;
	    cout<<answer(num,m)<<"\n";
	}
	return 0;
}
