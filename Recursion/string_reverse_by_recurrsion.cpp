#include <bits/stdc++.h>
using namespace std;
void reverse(string s)
{
	if (s.length() == 0)
		return;
	string ros = s.substr(1); // 1st index ke baad wali string aa jayegi
	// cout<<ros<<"\n";
	reverse(ros);
	cout << s[0] << " ";
}
int main()
{
	// your code goes here
	ios::sync_with_stdio(0);
	string s;
	cin >> s;
	// cout<<s.substr(0)<<"\n";
	reverse(s);
	return 0;
}
