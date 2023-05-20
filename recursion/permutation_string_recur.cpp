#include <bits/stdc++.h>
using namespace std;
void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << "\n";
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        permutation(ros, ans + ch);
    }
}
int main()
{
    // permutation of a string
    ios::sync_with_stdio(0);
    permutation("ABC", "");

    return 0;
}
