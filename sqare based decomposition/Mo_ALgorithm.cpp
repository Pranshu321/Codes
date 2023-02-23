#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
#define ll long long int
int rootN;
struct Q
{ // maintaing all things for each query.
    int idx, l, r;
};
Q q[N];

bool compare(Q q1, Q q2)
{ // compare function to order the queries in basic function
    if (q1.l / rootN == q2.l / rootN)
    {
        return q1.r > q2.r;
    }
    return q1.l / rootN < q2.l / rootN;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    rootN = sqrtl(n); // sqare root decomposition
    int queries;
    cin >> queries;
    for (int i = 0; i < queries; i++)
    { // taking all queries in one go
        int l, r;
        cin >> l >> r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }
    vector<int> ans(queries);
    sort(q, q + queries, compare); // sorting queries
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    for (int i = 0; i < queries; i++)
    {
        l = q[i].l;
        r = q[i].r;
        l--;
        r--; // one based indexing

        while (curr_r < r)
        { // shiting the pointers
            curr_r++;
            curr_ans += a[curr_r];
        }

        while (curr_l < l)
        {
            curr_ans -= a[curr_l];
            curr_l++;
        }
        while (curr_l > l)
        {
            curr_l--;
            curr_ans += a[curr_l];
        }
        while (curr_r > r)
        {
            curr_ans -= a[curr_r];
            curr_r--;
        }
        ans[q[i].idx] = curr_ans;
    }
    for (int i = 0; i < queries; i++)
    {
        cout << ans[i] << "\n";
    }

    // cout<<"\n";

    return 0;
}

/*
  1    5    -2    6     8    -7    2    1    11
  |               |     |                     |
curr_l            l     r                   curr_r
*/