#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10, M = 1e9 + 7;
#define ll long long int
vector<long long> power(N);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int p = 31;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s = "na";
    string t = "apnaacollegena";
    int T = t.size(), S = s.size();
    power[0] = 1;
    for (int i = 1; i < N; i++)
    {
        power[i] = (power[i - 1] * p) % M; // power calculation
    }
    vector<long long> h(T + 1, 0);
    for (int i = 0; i < T; i++)
    {
        h[i + 1] = (h[i] + (t[i] - 'a' + 1) * power[i]) % M; // hash function on t string
    }

    long long h_s = 0;
    for (int i = 0; i < S; i++)
    {
        h_s = (h_s + (s[i] - 'a' + 1) * power[i]) % M; // hash function on s string
    }

    for (int i = 0; i + S - 1 < T; i++)
    {
        long long cur_h = (h[i + S] - h[i] + M) % M;
        if (cur_h == (h_s * power[i]) % M)
        {
            cout << "Found at index " << i << "\n";
        }
    }

    return 0;
}