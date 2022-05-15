#include <bits/stdc++.h>
using namespace std;
// hexadecimal to decimal....... :)
void answer(string s, int n)
{ int x=1,ans=0;
    for(int i=n-1;i>=0;i--)
    { if(s[i]>='0' && s[i]<='9')
        {ans+= x*(s[i]-'0');}
        else if(s[i]>='A' && s[i]<='F')
        {ans+=x*((s[i]-'A')+10);}
    x*=16;}
cout<<ans;
    
}
int main() {
	// your code goes here
	string s;
	cin>>s;
	int n=s.length();
	answer(s,n);
	return 0;
}
