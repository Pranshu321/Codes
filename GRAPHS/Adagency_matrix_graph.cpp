#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adm(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adm[x][y] = 1;
        adm[y][x] = 1;
    }
    cout << "Adjagency matrix is \n";
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cout << adm[i][j] << " ";
        }
        cout << "\n";
    }
    // if(adm[3][7]==1){ // it is method to thta There is a node in between or not
    //     cout<<" \n There is edge in between";
    // }
    // else{
    //     cout<<"No edge \n";
    // }

    return 0;
}