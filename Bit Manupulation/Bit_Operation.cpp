#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

class Bitmanupulation
{
public:
    int getBit(int n, int pos)
    {
        return (1 & (n >> pos));
    }

    void setbit(int n, int pos)
    {
        print((n | (1 << pos)));
    }

    void unset(int n, int pos)
    {
        print((n & (~(1 << pos))));
    }

    void ToogleBit(int n, int pos)
    {
        print(n ^ (1 << pos));
    }

    bool bitsInAlternatePattern(int n){
        return (n ^ (n >> 1));
    }

    int countBit(int n)
    {
        int i = 0, count = 0;
        while (i < 32)
        {
            count += (n & 1);
            n = n >> 1;
            i++;
        }
        return count;
    }

    void print(int n)
    {
        for (int i = 3; i >= 0; i--)
        {
            cout << ((n >> i) & 1);
        }
        cout << "\n";
    }
};
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Bitmanupulation b;
    b.print(5);
    b.setbit(5, 1);
    b.unset(5, 0);
    b.ToogleBit(5, 0);
    // cout << b.countBit(15);
    cout<<b.bitsInAlternatePattern(8);

    return 0;
}