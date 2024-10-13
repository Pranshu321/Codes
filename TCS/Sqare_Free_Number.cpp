#include <bits/stdc++.h>

using namespace std;

#define int long long

bool Sqare_Free_Number(int n)
{
    if (n % 2 == 0)
    {
        n = n / 2;
    }
    if (n % 2 == 0)
    {
        return false;
    }

    for (int i = 3; i < sqrt(n); i += 2)
    {
        if (n % i == 0)
        {
            n = n / i;
            if (n % i == 0)
                return false;
        }
    }

    return true;
}

int32_t
main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (Sqare_Free_Number(i))
            {
                ans++;
            }
            if (Sqare_Free_Number(n / i))
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}