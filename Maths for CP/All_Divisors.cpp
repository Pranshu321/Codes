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
    // int i = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";  // 1 to root(n) divisors
    }

    for (int i = sqrt(n); i >= 1; i--)
    {
        if (n % i == 0)
            cout << (n / i) << " "; // root(n) to 1 divisors
    }

    return 0;
}