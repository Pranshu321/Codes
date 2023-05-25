#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    deque<int> d;
    while (1)
    {
        int x;
        cin >> x;
        if (x == -1)
        {
            break;
        }
        d.push_back(x);
    }
    
    d.pop_front();
    d.push_front(0);

    for (auto i : d)
    {
        cout << i << " ";
    }

    return 0;
}