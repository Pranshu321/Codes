// C++ program to find XOR of numbers
// from 1 to n.
#include <bits/stdc++.h>
using namespace std;

// Method to calculate xor
int XOR_1_To_N(int n)
{
    if (n % 4 == 0)
        return n;

    if (n % 4 == 1)
        return 1;

    if (n % 4 == 2)
        return n + 1;

    return 0;
}

int main()
{
    int n = 6;
    cout << XOR_1_To_N(n);
}
