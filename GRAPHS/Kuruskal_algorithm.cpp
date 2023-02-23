#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 1000;
// Minimum spanning tree
vector<int> parent(N);
vector<int> Size(N);
void make_set(int v)
{
	parent[v] = v;
	Size[v] = 1;
}
int Find_set(int v)
{
	if (v == parent[v])
		return v;
	return parent[v] = Find_set(parent[v]);
}
void Union_set(int a, int b)
{
	a = Find_set(a);
	b = Find_set(b);
	if (a != b)
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj.push_back({w, u, v});
	}
	sort(adj.begin(), adj.end());
	int cost = 0;
	for (auto i : adj)
	{
		int w = i[0];
		int u = i[1];
		int v = i[2];
		int x = Find_set(u);
		int y = Find_set(v);
		if (x == y)
			continue;
		else
		{
			cout << u << " " << v << "\n";
			cost = cost + w;
			Union_set(u, v);
		}
	}
	cout << cost;
	return 0;
}
/*8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1*/