#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void print(int n)
{
    for (int i = 3; i >= 0; i--)
    {
        cout << ((n >> i) & 1);
    }
    cout << "\n";
}

int get_bit(int n, int pos)
{
    // 0011
    //  0001
    return ((n & (1 << pos)));
}
void Set(int n, int pos)
{
    print((n | (1 << pos)));
}

int count_bit(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            count++;
        }
        n = n / 2;
    }
    return count;
}
void toggle(int n, int pos)
{
    print((n ^ (1 << pos)));
}
void Unset(int n, int pos)
{
    print((n & (~(1 << pos))));
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a = 5;
    cout << get_bit(5, 1) << "\n";
    print(a);
    Set(a, 1);
    Unset(a, 0);
    // cout << get_bit(a, 1);
    // cout << "\n" << count_bit(7) << "\n";
    int b = 2 << 1;
    cout << b;
    toggle(a, 1);

    return 0;
}