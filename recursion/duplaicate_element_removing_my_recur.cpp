#include <bits/stdc++.h>
using namespace std;
string removeduplicate(string s)
{ if(s.length()==0)
    return "";
    char ch=s[0];
    string ans= removeduplicate(s.substr(1));
    if(ch==ans[0]) // this check if the the ans string first element is equal throw
    // ch or not if equal means we have to remove it so we return ans,
    { return ans;
        
    }
    return (ch+ans);
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout<<removeduplicate("aaaabbbbcccddsssee");
	return 0;
}
