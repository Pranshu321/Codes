#include <bits/stdc++.h>

using namespace std;

#define int long long

int factorial(int n)
{
    if (n == 0)
        return 0;
    int partialAns = factorial(n - 1);
    // cout << n << " ";
    return n + partialAns;
}

int32_t
main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    cout << "\n"
         << factorial(n);

    return 0;
}