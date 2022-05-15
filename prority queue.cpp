#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes he
	//this is for printing in acending order...
	priority_queue <int, vector<int> , greater<int> >  q;
	priority_queue <int, vector<int> >  q1;
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{ int a; cin>>a;
	    q.push(a);
	    q1.push(a);
	}
	cout<<"contents of q in acending "<<"\n";
	while(!q.empty())
	{ cout<<q.top()<<"\n";
	    q.pop();
	} 	cout<<"contents of q1 in decending "<<"\n";cout<<"\n";
		while(!q1.empty())
	{ cout<<q1.top()<<"\n";
	    q1.pop();
	}
	return 0;
}
