#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    char A[] = "painter";
    char B[] = "painting";
    int i, j;

    for (int i = 0, j = 0; A[i] != '\0', B[i] != '\0'; i++, j++)
    {
        if (A[i] != B[j])
        {
            break;
        }
        if (A[i] == B[j])
        {
            cout << "Equal\n";
        }
        if (A[i] < B[j])
            cout << "Greater\n";

        if (A[i] < B[j])
            cout << "Smaller\n";
    }

    return 0;
}