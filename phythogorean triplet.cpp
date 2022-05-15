#include <bits/stdc++.h>
using namespace std;
bool phyto(int x,int y, int z)
{ int m = max(x,max(y,z));
   int b,c;
   if(m==x)
   { b=y; c=z;}
   else if(m==y)
   { b=x; c=z;}
   else
   { b=x; c=y;}
   if(m*m==b*b+c*c)
   return true;
   else
   return false;
}
int main() {
	// your code goes here
	int x,y,z,c=0;
	cin>>x>>y>>z;
	if(phyto(x,y,z))
	cout<<"it is an phyrogorean triplet";
	else
	cout<<"\n not an triplet";
	
	
	return 0;
}
