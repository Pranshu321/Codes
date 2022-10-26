#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int N = 10000;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int dp[N];
int lis(int a[], int idx)
{
  if (dp[idx] != -1)
    return dp[idx];

  dp[idx] = 1; // Single element also a List

  for (int i = 0; i < idx; i++)
  {
    if (a[idx] > a[i])
      dp[idx] = max(dp[idx], 1 + lis(a, i));
  }

  return dp[idx];
}
int main()

{
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));

  cout << lis(a, n - 1);

  return 0;
}