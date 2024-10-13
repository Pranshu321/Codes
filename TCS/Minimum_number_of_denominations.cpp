#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        /* code */
        int n;
        cin >> n;
        int count = 0;
        while (n)
        {
            count++;
            n = n / 2;
        }
        cout << count << "\n";
    }

    return 0;
}