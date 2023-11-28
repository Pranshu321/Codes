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
    int res = 1;
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
        // cout<<n<<"\n";
        res = res * (count + 1);
    }
    // cout << "fdf " << n << "\n";
    if (n >= 2)
    {
        cout << res * 2;
    }
    else
    {

        cout << res;
    }

    return 0;
}