#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// this not an optimize approach;
int catalan(int n){
    if(n<=1)
    return 1;
    int res=0;
    for(int i=0;i<=n-1;i++){
        res+= catalan(i)*catalan(n-i-1);
    }
    return res;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	for(int i=0;i<=10;i++)
	cout<<catalan(i)<<"\n";
	return 0;
}
