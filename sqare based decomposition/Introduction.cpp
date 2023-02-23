#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], b[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int len = (sqrt(n) + 1);
    for (int i = 0; i < n; i++)
    {
        b[i / len] += a[i];
    }
    int sum = 0;
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        sum = 0;
        cin >> l >> r;
        l--;
        r--;
        for (int i = l; i <= r;)
        {
            if (i % len == 0 && i + len - 1 <= r)
            { // in this we are checking that the one block is starting and full is covering or not .
                sum += b[i / len];
                i += len;
            }
            else
            {
                sum += a[i];
                i++;
            }
        }

        cout << sum << " ";
    }

    return 0;
}