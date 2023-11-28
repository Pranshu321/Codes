#include <bits/stdc++.h>

using namespace std;

#define int long long

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    // Check from 2 to square root of n
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    int sq = sqrt(n);
    vector<bool> prime(sq + 1, true);

    for (int i = 2; i <= sq; i++)
    {
        if (prime[i])
        {
            cout << i * i << " ";
            for (int j = i * i; j <= sq; j += i)
            {
                prime[j] = false;
            }
        }
    }

    return 0;
}