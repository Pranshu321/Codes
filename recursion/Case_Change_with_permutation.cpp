#include <bits/stdc++.h>

using namespace std;
// This is the question in which we have to make pairs like that is if lower case ab is given we have to make aB,Ab,AB,ab;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void Case_Change(string ip, string op)
{
    if (ip.empty())
    {
        cout << op << "\n";
        return;
    }
    string op1 = op;
    string op2 = op;

    op1.push_back(ip[0]);
    op2.push_back(toupper(ip[0]));
    ip.erase(ip.begin() + 0);

    Case_Change(ip, op1);
    Case_Change(ip, op2);
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string ip;
    cin >> ip;
    string op = "";
    cout << "-------------Case Change---------------\n";
    Case_Change(ip, op);

    return 0;
}