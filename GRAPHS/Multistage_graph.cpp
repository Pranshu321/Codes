#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

const int INF = INT_MAX;
#define N 8
int shortestDist(int graph[N][N])
{
    int dist[N];

    dist[N - 1] = 0;

    for (int i = N - 2; i >= 0; i--)
    {
        dist[i] = INF;

        for (int j = i; j < N; j++)
        {
            if (graph[i][j] == INF)
            {
                continue;
            }
            dist[i] = min(dist[i], graph[i][j] + dist[j]);
        }
    }
    return dist[0];
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int graph[N][N] =
        {{INF, 1, 2, 5, INF, INF, INF, INF},
         {INF, INF, INF, INF, 4, 11, INF, INF},
         {INF, INF, INF, INF, 9, 5, 16, INF},
         {INF, INF, INF, INF, INF, INF, 2, INF},
         {INF, INF, INF, INF, INF, INF, INF, 18},
         {INF, INF, INF, INF, INF, INF, INF, 13},
         {INF, INF, INF, INF, INF, INF, INF, 2},
         {INF, INF, INF, INF, INF, INF, INF, INF}};

    cout << "The shortest path from the multistage graph is : " << shortestDist(graph);
    return 0;
}