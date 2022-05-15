#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

/*
Approach :-
1. whenever l and i are on same pos we dont have to swap.
2. when l and i are on same position we have to swap.
3. when l and r equal we have to print string.

4. For each call we also habe to increase the i .... eg:- starting we have ABC and i on A , but when we take permu. we have to take the i on B in ABC.

*/

void Permutations(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << "\n";
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[r]); // Here we take case we swap the elements that are at postion l and r;
            Permutations(s, l + 1, r);
            swap(s[l], s[i]); // Here we correct our swap and its like the backtraking.
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    cout << "\nPermutations are \n\n";
    Permutations(s, 0, s.length() - 1);

    return 0;
}