#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void power_sets(string s, string op)
{

    if (s.empty())
    {
        if (op.length() == 0)
        {
            cout << "Empty String\n";
            return;
        }
        cout << op << "\n";
        return;
    }
    string op1 = op; // In this string we take the decision of not taking the element
    string op2 = op; // In this we take the elelent or we can say all the right decisions.

    op2.push_back(s[0]);
    s.erase(s.begin() + 0);

    power_sets(s, op1);
    power_sets(s, op2);
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s, op = "";
    cin >> s;
    cout << "---------- Power Sets------------\n";
    power_sets(s, op);

    return 0;
}