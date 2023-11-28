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
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int repeat = 0;
    int missing = 0;
    int i = 0;
    while (i < n)
    {
        if (a[a[i] - 1] != a[i])
        {
            swap(a[i], a[a[i] - 1]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            repeat = a[i];
            missing = i + 1;
            break;
        }
    }

    cout << repeat << " " << missing << endl;

    return 0;
}