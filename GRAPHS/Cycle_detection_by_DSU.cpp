#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> Size(N);
void make_set(int v)
{
	parent[v] = v;
	Size[v] = 1;
}
int find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}
void union_set(int a, int b)
{
	int x = find_set(a);
	int y = find_set(b);
	if (x != y)
	{
		if (Size[a] < Size[b])
			swap(a, b);
		parent[b] = a;
		Size[a] += Size[b];
	}
}
int32_t main()
{
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	for (int i = 0; i < N; i++)
		make_set(i);
	bool present = false;
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj.push_back({u, v});
	}
	for (auto i : adj)
	{
		int x = i[0];
		int y = i[1];
		int a = find_set(x);
		int b = find_set(y);
		if (a == b)
			present = true;
		else
			union_set(x, y);
	}
	if (present)
	{
		cout << "Cycle is present";
	}
	else
	{
		cout << "Cycle is not present";
	}

	return 0;
}