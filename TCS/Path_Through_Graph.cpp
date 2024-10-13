#include <bits/stdc++.h>

using namespace std;

#define int long long

#define endl '\n'

int get(int x)

{

    for (int i = 2; i * i <= x; i++)

    {

        if (x % i == 0)
            return x / i;
    }

    return 1;
}

void sol()

{

    int x, y;

    cin >> x >> y;

    if (x < y)
        swap(x, y);

    if (x == y)
    {
        cout << 0;
        return;
    }

    map<int, int> m;

    int c = 0;

    while (x != 1)

    {

        c++;

        x = get(x);

        m[x] = c;
    }

    c = 0;

    while (!m.count(y))

    {

        c++;

        y = get(y);
    }

    cout << c + m[y];
}

int32_t main()

{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sol();

    return 0;
}