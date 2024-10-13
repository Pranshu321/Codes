#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // lower bound
    vector<int> a = {1, 2, 3, 4, 6, 6, 7};
// agar element present hai tho usko return karega varna usse bada jo present to return karega. (location Return)
    cout <<*lower_bound(a.begin(), a.end(), 5)<<"\n";
    cout <<*upper_bound(a.begin(), a.end(), 1);
    return 0;
}