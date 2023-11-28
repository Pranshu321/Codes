#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int a = 4, b = 6;
    // swapping
    a = a ^ b;

    // b = b ^ ( a ^ b ) = b^b^a = 0^a = a
    b = b ^ a;

    // a = a ^ ( a ^ b )
    a = a ^ b;

    cout << a << " " << b;

    return 0;
}