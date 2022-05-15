#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

class sample
{
    int a = 21;

protected:
    int b = 23;

public:
    int c = 10;
    friend int func();
};

int func()
{
    sample s;
    int sum = s.a + s.b + s.c;
    return sum;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cout << func;

    return 0;
}