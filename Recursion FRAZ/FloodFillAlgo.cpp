#include <bits/stdc++.h>

using namespace std;

#define int long long

// Flood Fill

void flood(vector<vector<int>> &image, int i, int j, int colcolor, int newColor)
{
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != colcolor)
    {
        return;
    }
    image[i][j]=newColor;
    flood(image, i+1, j, colcolor, newColor);
    flood(image, i, j+1, colcolor, newColor);
    flood(image, i-1, j, colcolor, newColor);
    flood(image, i, j-1, colcolor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{

    int colcolor = image[sr][sc];
    if (colcolor == newColor)
    {
        return image;
    }
    flood(image, sr, sc, colcolor, newColor);
    return image;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
        }
    }

    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    auto ans = floodFill(g, sr, sc, newColor);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}