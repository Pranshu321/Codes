#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int inf = 1e7 + 10;
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<vector<int>> graph = {
        {10, 8, inf, 11, inf},
        {1, 0, 3, 5, inf},
        {8, 0, 0, 1, 2},
        {1, inf, inf, 0, 0},
        {7, 9, 4, 6, inf}};
    int n = graph.size();
    vector<vector<int>> dist = graph;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                { // relaxing the nodes
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == inf)
                cout << "inf" << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}