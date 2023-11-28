#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n = 3;
    cin >> n;

    //  if(n&1){
    //     cout<<"Odd";
    //  }
    //  else cout<<"Even";

    // Multiplication and Division
    cout << (n >> 1) << "\n";
    cout << (n << 2) << "\n";

    // To Uppercase and Lowercase using bit manupulation
    char c = 'a';
    cout << (char)(c | 32) << "\n";    // 32 == ' '
    cout << (char)(c & (~32)) << "\n"; // ~32 == '_'

    // Clear LSB
    int q = 59;
    int i = 4;
    int b = (q & (~(1 << (i + 1)) - 1));

    // MSB
    int bb = (q & ((1 << (i + 1)) - 1));
    cout << bb;

    // Check if power of two
    int y = 16;
    if ((y& (y - 1)) == 0)
    {
        cout << "Power of 2";
    }
    else
    {
        cout << "Not a power of 2";
    }

    return 0;
}