#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;
vector<vector<int>> a;
vector<vector<int>> dp;
vector<vector<int>> visited;

int dfs(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return (int)1e15-1;
    if (a[i][j] == 0)
        return 0;

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(visited[i][j]){
        return (int)1e15-1;
    }
    visited[i][j]=1;

    int ans=1e15;
    ans=min(ans , dfs(i+1,j));
    ans=min(ans , dfs(i-1,j));
    ans=min(ans , dfs(i,j+1));
    ans=min(ans , dfs(i,j-1));

    return dp[i][j]=ans+1;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    a.assign(n, vector<int>(m));
    dp.assign(n, vector<int>(m, -1));
    visited.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << dfs(i, j) ;
        }
        cout << "\n";
    }

    return 0;
}
