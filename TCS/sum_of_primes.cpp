#include <bits/stdc++.h>

using namespace std;

#define int long long

bool prime[3000];
void seive(int n)
{
    memset(prime, true, sizeof(prime));

    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    seive(n);
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        int sum = 2;
        if (prime[i])
        {
            for (int j = 3; j < n; j++)
            {
                if (prime[j])
                {

                    sum += j;
                    if (i == sum)
                    {
                        count++;
                        break;
                    }
                    if (sum > i)
                    {
                        break;
                    }
                }
            }
        }
    }
    cout << count;

    return 0;
}