#include <bits/stdc++.h>
using namespace std;
void replacepi(string s)
{ if(s.length()==0)
    return;
    if(s[0]=='p' && s[1]=='i') // checking that pi exist or not by checking two consecutive character
        { cout<<"3.14";
        replacepi(s.substr(2));
    }
    else{
    cout<<s[0]; //this when pi character not found so full string print as it is
    replacepi(s.substr(1));}
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	replacepi(s);
	return 0;
}
