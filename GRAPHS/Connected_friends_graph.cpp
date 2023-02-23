#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int n, m;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> Comp;
int get_size(int idx)
{
	if (vis[idx])
	{
		return 0;
	}
	vis[idx] = true;
	int ans = 1;
	for (auto i : adj[idx])
	{
		if (!vis[i])
		{
			ans += get_size(i);
			vis[idx] = true;
		}
	}
	return ans;
}
int32_t main()
{
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	adj = vector<vector<int>>(n);
	vis = vector<bool>(n, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
			Comp.push_back(get_size(i));
	}
	ll ans = 0;
	for (auto i : Comp)
	{
		ans += i * (n - i);
	}
	cout << ans / 2;
	return 0;
}