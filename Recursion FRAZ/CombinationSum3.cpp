#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(vector<int> &a, int idx, vector<int> &temp, int k, int sum)
{
    if (k == 0 && sum == 0)
    {
        for (auto i : temp)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    if (k > a.size() - idx + 1)
    {
        return;
    }
    if (k == 0 && sum > 0)
    {
        return;
    }
    if (a[idx] > sum)
    {
        return;
    }
    if (idx >= a.size())
    {
        return;
    }
    if (a[idx] <= sum)
    {
        temp.push_back(a[idx]);
        solve(a, idx + 1, temp, k - 1, sum - a[idx]);
        temp.pop_back();
        solve(a, idx + 1, temp, k, sum);
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int k;
    cin >> k;

    vector<int> a;
    for (int i = 1; i <= 9; i++)
    {
        a.push_back(i);
    }

    int sum;
    cin >> sum;

    vector<int> temp;
    cout << "=========================\n";
    solve(a, 0, temp, k, sum);

    return 0;
}