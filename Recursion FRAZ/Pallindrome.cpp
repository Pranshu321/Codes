#include <bits/stdc++.h>

using namespace std;

#define int long long

bool pallindrome(string s, int l, int r)
{
    if (l >= r)
    {
        return true;
    }
    if (s[l] != s[r])
    {
        return false;
    }
    return pallindrome(s, l + 1, r - 1);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    int r = s.length();
    int l = 0;
    cout << pallindrome(s, l, r - 1);

    return 0;
}