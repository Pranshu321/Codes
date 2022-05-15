#include <bits/stdc++.h>
using namespace std;
int countone( int n)
{ int count=0;
while(n)
{ n=n&n-1;
    count++;
}
return count;}
int main() {
	// your code goes here
	int n; cin>>n;
	cout<<countone(n);
	return 0;
}
