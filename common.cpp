#include <bits/stdc++.h>
using namespace std;
int euclid(int a,int b)
{ while(b!=0)
    {int rem=a%b;
    a=b;
    b=rem;}
    return a;
    
}
int main() {
	// this is the program for the finding the highest common divisor by euclid 
	/* which is by taking the diffrence till the 0 came or same by remainder of 
	numbers till the remainder became 0;*/
	ios::sync_with_stdio(0);
	int a,b; cin>>a>>b;
	cout<<euclid(a,b);
	return 0;
}
