#include <bits/stdc++.h>

using namespace std;

#define int long long

int prime(int n)
{
    int x = n / 2;
    while (x > 1)
    {
        if (n % x == 0)
        {
            return false;
        }
        x--;
    }
    return true;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int d, p;
    cin >> d >> p;

    int n = d / p;
    int ans = 0;
    for (int i = 2; i < n; i++)
    {
        if (prime(i))
        {
            int time = true;
            for (int j = 0; j < p; j++)
            {
                int num = i + j * n;
                if (!prime(num))
                {
                    time = false;
                    break;
                }
            }
            if (time)
                ans++;
        }
    }

    cout << ans;

    return 0;
}