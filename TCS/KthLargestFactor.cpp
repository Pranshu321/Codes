#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int k;
    cin >> k;

    int sz = sqrt(n);
    vector<int> v;
    for (int i = 1; i <= sz; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (n / i == i)
                v.push_back(i);
        }
    }
    cout << v[k - 1];

    return 0;
}