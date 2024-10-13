#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int pr;
    float longitude, time;
    cin >> pr >> longitude;
    float peroid_of_rotation = (float)pr;
    
    time = (peroid_of_rotation / 360.00) * longitude * 60;

    // For Getting the hour
    int h = (int)time / 60;

    // For getting the minutes
    int m = (int)time - (h * 60);

    // Hours are in 12 hours format
    float H = h % 12;
    float M = m;
    //Standard Formula
    float angle = (11.0 / 2.0) * M - (30.0 * H);
    if (angle < 0)
    {
        cout << fixed << setprecision(2) << angle + 360;
    }
    else
    {
        cout << fixed << setprecision(2) << angle;
    }

    return 0;
}