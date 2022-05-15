#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int32_t main()
{
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	string s;
	cin >> s;
	stack<char> st;
	ll ans = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
			st.push(s[i]);
		else if (s[i] == '(')
			st.push(s[i]);
		else if (s[i] == ')')
		{
			if (st.top() == '(')
				ans++;
			while (st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
			{
				st.pop();
			}
			st.pop();
		}
	}
	cout << ans;
	return 0;
}
