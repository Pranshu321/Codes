#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n = 4;
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int src=2 , dest=3;
    // remove the edge from src to dest
    adj[src].erase(remove(adj[src].begin(), adj[src].end(), dest), adj[src].end());
    // remove the edge from dest to src
    adj[dest].erase(remove(adj[dest].begin(), adj[dest].end(), src), adj[dest].end());

    for(auto i : adj){
        cout<<i.first<<"->";
        for(auto j : i.second){
            cout<<j<<"->";
        }
        cout<<"\n";
    }

    /*
    Pros:
    - Space Efficient for sparse graphs
    - Good for dynamic graphs
    - easy to iterate over neighbors

    Cons:
    - slower edge queries
    - Overead for storage
    - less intuitive for dense graphs
    */


    return 0;
}