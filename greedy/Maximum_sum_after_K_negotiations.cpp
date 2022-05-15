#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

int K_negotiations(int a[], int n, int k)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0 and k > 0)
        {
            a[i] = -a[i];
            k--;
        }
    }
    int sum = accumulate(a, a + n, 0);
    int mini = *(min_element(a, a + n));

    if (k & 1)
    {
        sum -= 2 * mini;
    }
    return sum;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, k;
    cin>>n>>k;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Max sum after the k negotiations : " << K_negotiations(a, n, k);

    return 0;
}