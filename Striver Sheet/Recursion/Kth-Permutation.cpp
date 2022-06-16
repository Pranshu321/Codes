#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

string find_kth(int n, int k)
{
    int fact = 1;  // To find the total number of permtations that can available.
    vector<int> v; // Storng the numbers from which the permutations is making
    for (int i = 1; i < n; i++)
    {
        fact *= i;      // Find all total possiblilies n!
        v.push_back(i); // storing the numbers
    }
    v.push_back(n);
    k--;             // Decreasing the by one as we want 0 based indexing
    string ans = ""; // For storing the answer
    while (1)
    {
        ans += to_string(v[(k / fact)]); // Finding the block where our permutations can be present
        v.erase(v.begin() + (k / fact)); // Erasing that instance as it added to our answer
        if (v.size() == 0)               // Checking if number vector empty that means our answer is calculated.
        {
            break;
        }
        k = k % fact;           // decreasing the window size or we say finding deep for next numbers of permutations in deep blocks.
        fact = fact / v.size(); // update fact as numbers of elements decreases.
    }

    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    int k;
    cin >> n >> k;

    cout << find_kth(n, k);

    return 0;
}