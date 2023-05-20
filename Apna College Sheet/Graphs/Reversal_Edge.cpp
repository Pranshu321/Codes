#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;
    list<pair<int, int>> *graph;

public:
    // Constructor:
    Graph(int V)
    {
        this->V = V;
        graph = new list<pair<int, int>>[V];
    }

    // Adding edges into the graph:
    void addEdge(int u, int v, int w)
    {
        graph[u].push_back(make_pair(v, w));
    }

    // Returns shortest path from source to all other vertices.
    vector<int> shortestPath(int source)
    {
        set<pair<int, int>> s;
        vector<int> dist(V, INF);
        s.insert({0, source});
        dist[source] = 0;

        while (!s.empty())
        {
            auto x = *(s.begin());
            s.erase(x);

            int u = x.second;
            for (auto i : graph[u])
            {
                int v = i.first;
                int w = i.second;
                if (dist[u] + w < dist[v])
                {
                    if (dist[v] != INF)
                    {
                        s.erase({dist[v], v});
                    }
                    dist[v] = dist[u] + w;
                    s.insert({dist[v], v});
                }
            }
        }
        return dist;
    }

    Graph modelGraphWithEdgeWeight(int edge[][2], int E, int V)
    {
        Graph g(V);
        for (int i = 0; i < E; i++)
        {
            // original edge : weight 0
            g.addEdge(edge[i][0], edge[i][1], 0);

            // reverse edge : weight 1
            g.addEdge(edge[i][1], edge[i][0], 1);
        }
        return g;
    }

    int getMinEdgeReversal(int edge[][2], int E, int V, int source, int destination)
    {
        // get modified graph with edge weight.
        Graph g = modelGraphWithEdgeWeight(edge, E, V);

        // distance vector stores shortest path.
        vector<int> dist = g.shortestPath(source);

        // If distance of destination is still INF then we cannot reach destination. Hence, not possible.
        if (dist[destination] == INF)
            return -1;
        else
            return dist[destination];
    }
};

int main()
{
    int V = 7;
    Graph g(V);

    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1}, {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse = g.getMinEdgeReversal(edge, E, V, 0, 6);

    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not Possible." << endl;

    return 0;
}