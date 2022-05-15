#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
string Number(int s, int d)
{
    if ((9 * d) < s)
    {
        return "Not Possible";
    }
    string ans = "";
    for (int i = d - 1; i >= 0; i--) // we starting from last and adding the largest number possible that is nine.
    {
        if (s > 9) // If sum if greater than then only we add 9.
        {
            ans = '9' + ans;
            s -= 9;
        }
        else
        {
            if (i == 0) // If i=0 ...) then add left over sum.
            {
                ans = to_string(s) + ans;
            }
            else
            {
                ans = to_string(s - 1) + ans; // Adding the sum-1 to the position on which i is pointing...other than zero.
                i--;
                while (i > 0) // else all position zero
                {
                    ans = '0' + ans;
                    i--;
                }
                ans = '1' + ans; // At last at first position 1.
                break;
            }
        }
    }
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int sum, digit;
    cin >> sum >> digit;

    cout << "The smallest Number is : " << Number(sum, digit);

    return 0;
}