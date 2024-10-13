#include <bits/stdc++.h>

using namespace std;

#define int long long

int power(int n, int p)
{
    if (p == 0 || n == 0)
    {
        return 1;
    }
    if (p == 1)
    {
        return n;
    }
    // return n * power(n, p - 1);
    if (n % 2 == 1)
    {
        return power(n, p / 2) * power(n, p / 2) * n;
    }
    return power(n, p / 2) * power(n, p / 2);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int p;
    cin >> p;
    cout << power(n, p);

    return 0;
}