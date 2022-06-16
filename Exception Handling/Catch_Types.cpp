#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int divi(int a, int b)
{
    if (b == 0)
    {
        throw 1.7;
    }
    return a / b;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a = 10, b = 0;
    try
    {
        int div = divi(a, b);
        cout << div;
    }
    catch (int e)
    {
        cout << "Int Val thrown";
    }
    catch (double e)
    {
        cout << "Double Val thrown";
    }
    catch (char e)
    {
        cout << "Char Val thrown";
    }
    catch (string e)
    {
        cout << "string Val thrown";
    }
    catch (...)
    {
        cout << "All catches handeled";
    }

    return 0;
}