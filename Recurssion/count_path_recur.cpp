#include <bits/stdc++.h>
using namespace std;
int count_path(int s,int e)
{ if(s==e)
    return 1;
    if(s>e)
    return 0;
    int count=0;
    for(int i=1;i<=6;i++)
    { count+=count_path(s+i,e);
    } 
    return count;
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout<<count_path(0,3);
	return 0;
}
