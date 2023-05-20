#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    list<int> l;

    for (int i = 0; i < n; i++)
    {
        l.push_back(i);
    }

    auto it = l.begin();
    while (l.size() > 1)
    {
        for (int i = 1; i < k; i++)
        {
            it++;
            if (it == l.end())
            {
                it = l.begin();
            }
        }
        it = l.erase(it);
        if (it == l.end())
        {
            it = l.begin();
        }
    }

    cout << "Position is : " << l.front();

    return 0;
}