#include <bits/stdc++.h>

using namespace std;

#define int long long

int counti = 0;
int mini = INT_MAX;

int permutations(string s, int idx, int n, int p)
{
    if (idx == n)
    {
        int test = stoi(s);
        if (test > p && test < mini)
        {
            counti = 1;
            mini = test;
        }
    }
    else
    {
        for (int i = idx; i <= n; i++)
        {
            swap(s[i], s[idx]);
            permutations(s, idx + 1, n, p);
            swap(s[i], s[idx]);
        }
    }
    return mini;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int a;
    cin >> a;
    int b;
    cin >> b;
    string s = to_string(a);
    int len = s.length();
    int h = permutations(s, 0, len - 1, b);

    counti ? cout << h : cout << -1;

    return 0;
}