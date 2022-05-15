#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int GCD(int a,int b){
    return (b==0)?a:GCD(b,a%b); // a>=b thats why only a%b implement
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cout<<GCD(5,20)<<"\n";
	cout<<__gcd(20,5);
	return 0;
}
