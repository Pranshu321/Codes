#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void solve(ll a[], ll st, ll end, vector<ll> &v)
{
    ll s = 0;
    ll n = end - st+ 1;
    for (ll i = 0; i < (1 << n); i++)
    { // Sequence in array
        s = 0;
        ll j = st;
        ll x = i;
        while (x)
        {
            ll bit = x & 1;
            if (bit)
            {
                s += a[j];
            }
            j++;
            x = x>>1;
        }
        v.push_back(s);
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> v1, v2;
    solve(arr, 0, (n / 2) - 1, v1);
    solve(arr, (n / 2), n - 1, v2);
    sort(v2.begin(), v2.end());
    ll count = 0;
    for (ll i = 0; i < v1.size(); i++)
    {
        ll low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin();  // simply searching as lower bound
        ll high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin(); // simply searching as upper bound
        count += (high - low);
    }
    cout << count<<"\n";

    return 0;
}