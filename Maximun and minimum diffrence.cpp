#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int n; cin>>n;
int a[n];
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n);
ll mn=0,mx=0;
for(int i=0;i<n/2;i++){
    mx+=a[i+n/2]-a[i];
    mn+=a[i*2+1]-a[i*2];
}
cout<<mn<<" "<<mx;

	
	return 0;
}