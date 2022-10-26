#include <bits/stdc++.h>
using namespace std;
void elements(string s, string ans)
{if(s.length()==0)
    { cout<<ans<<"\n";
        return;
    }
    char ch=s[0];
    string ros=s.substr(1);
    elements(ros,ans); //in this ros at last call have the last element B and answer will always have empty string;
    elements(ros,ans+ch); //and in this add the character 
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	elements("ABC","");
	return 0;
}
