#include <bits/stdc++.h>
using namespace std;
int answer(int n,int a,int b)
{ int c1=n/a;
    int c2=n/b;
    int c3=n/(a*b);
    return c1+c2-c3;
}
int main() {
	// number divisible by the number given two number
	int n,a,b; cin>>n>>a>>b;
	cout<<answer(n,a,b);
	return 0;
}
