#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	stack<int> s;
	int n;
	cin>>n;
	while(n--)
	{ int a; cin>>a;
	    s.push(a);
	}
	s.emplace(6); // its work is to place the element at the top of the top
	// element present in the stack :)-
	while(!s.empty())
	{ cout<<s.top()<<" ";
	    s.pop();
	}
	return 0;
}
