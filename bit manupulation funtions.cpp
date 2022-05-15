#include <bits/stdc++.h>
using namespace std;
int getbit(int n, int pos)
{return ((n&(1<<pos))!=0);}
int setbit(int n,int pos)
{return ((n|(1<<pos)));}
int clearbit(int n,int pos)
{ int mask = ~(1<<pos);
    return ((n&(mask)));}
int updatebit(int n, int pos, int val)
{ int mask= ~(1<<pos);
    n=n&mask;
    return((n|(val<<pos)));
}
int main() {
	// your code goes here
	cout<<getbit(1,1)<<"\n";
		cout<<setbit(9,2)<<endl;
		cout<<clearbit(7,2)<<endl;
		cout<<updatebit(4,1,1)<<endl;
	return 0;
}
