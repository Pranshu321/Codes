#include <bits/stdc++.h>
using namespace std;
int paringfriends(int n)
{ if(n==0 || n==1 || n==2)
    return n;
    return (paringfriends(n-1)+(paringfriends(n-2)*(n-1)));
    /* in this n-1 shows that last nth person left unpaired and n-2 shows
    that he is paired that for pairing of that there are n-1 ways.*/
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout<<paringfriends(4);
	return 0;
}
