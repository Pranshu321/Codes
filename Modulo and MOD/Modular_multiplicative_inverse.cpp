#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

// Formula of the multiplicative inverse is like :- (a^M-2)%M;

const int M = 1e9 + 7;
int MultiplicativeInverse(int a, int b, int m)
{
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}
const int N = 1e6 + 10;
int fact[N];
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * 1LL * i) % M;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int n, k;
        cin >> n >> k;

        int ans = fact[n];
        int den = (fact[n - k] * 1LL * fact[k]) % M;
        ans = ans * MultiplicativeInverse(den, M - 2, M);
        cout << ans << "\n";
    }

    return 0;
}