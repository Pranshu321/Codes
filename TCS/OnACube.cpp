#include <bits/stdc++.h>

using namespace std;

#define PI 3.14

#define int long long

/*
On a cube is a problem in which we have compute the distance we have cover as if the point on the same face then we have follow the ARC STURUCTURE and if the point on the different face then we have follow the shortest distance.

(on same face z1==z2)
ARC = (PI * (abs(x2 - x1))) / 3

(Different Face)

shortest distance

*/

double distance(int x1, int y1, int z1, int x2, int y2, int z2)
{
    double dist = 0;

    if (z1 == z2 and (y2 == y1 or x2 == x1) and z2 != 0)
    {
        if (x1 != x2)
        {
            dist = (PI * (abs(x2 - x1))) / 3;
        }

        else
        {
            dist = (PI * (abs(y2 - y1))) / 3;
        }
    }
    else
    {
        dist = (int)(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)) + abs(z2 - z1));
    }
    return dist;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[3 * n];
    int k = 3 * n;
    for (int i = 0; i < 3 * n; i++)
    {
        cin >> a[i];
    }

    int x1 = a[0];
    int y1 = a[1];
    int z1 = a[2];
    double ans = 0;
    for (int i = 3; i < k; i += 3)
    {
        auto temp = distance(x1, y1, z1, a[i], a[i + 1], a[i + 2]);
        x1 = a[i];
        y1 = a[i + 1];
        z1 = a[i + 2];
        ans += temp;
    }
    // round to 2 decimal point
    printf("%.2f", ans);

    return 0;
}