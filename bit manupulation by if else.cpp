#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{ int n,a; cin>>n>>a;
	    if(n==1)
	    { int pos; cin>>pos;
	       int b= 1<<pos;
	       if((a&b)!=0);
	       cout<<1<<"\n";
	    }
	    if(n==2)
	    { int pos; cin>>pos;
	        int b = 1<<pos;
	        cout<<(a|b)<<"\n";
	    }
	    if(n==3)
	    { int pos; cin>>pos;
	        int b= ~(1<<pos);
	        cout<<(a&b)<<"\n";
	    }
	    if(n==4)
	    {int pos, val; cin>>pos>>val;
 int mask= ~(1<<pos);
    a=a&mask;
    cout<<(a|(val<<pos))<<"\n";
}

	    }
	
	return 0;
}
