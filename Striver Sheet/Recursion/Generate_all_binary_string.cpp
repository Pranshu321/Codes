#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<vector<int>> res;
void all_binary(vector<int> &a, int k, int i)
{
    if (i == k)
    {
        res.push_back(a);
        return;
    }

    else if (a[i - 1] == 1)
    {
        a[i] = 0;
        all_binary(a, k, i + 1);
    }
    else
    {
        a[i] = 0;
        all_binary(a, k, i + 1);
        a[i] = 1;
        all_binary(a, k, i + 1);
    }
}

void solve(vector<int> &a, int k)
{
    if (k <= 0)
    {
        return;
    }
    a[0] = 0;
    all_binary(a, k, 1);
    a[0] = 1;
    all_binary(a, k, 1);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int s;
    cin >> s;

    vector<int> ans(s);
    solve(ans, s);
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << "";
        }
        cout << " ";
    }

    return 0;
}