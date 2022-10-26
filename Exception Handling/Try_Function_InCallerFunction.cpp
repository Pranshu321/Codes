#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

class Myexception:public exception
{

};
int divi(int a, int b)throw(Myexception)
{
    if (b == 0)
    {
        throw Myexception();
    }
    return a / b;
}
int main()

{
    ios_base::sync_with_stdio(false);

    cout.tie(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    try
    {
        int div = divi(a, b);
        cout << div;
    }
    catch (Myexception e)
    {
        cout << "Division by zero is not allowed ";
    }

    return 0;
}