#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void solve(vector<vector<int>> &matrix, int n, int m)
{
    bool col = true;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
            col = false;
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;
        }
        if (!col)
            matrix[i][0] = 0;
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    for (int i = 0; i < n; i++)
    {
        vector<int> s;
        for (int j = 0; j < m; j++)
        {
            int a;
            cin >> a;
            s.push_back(a);
        }
        matrix.push_back(s);
    }

    solve(matrix, n, m);

    cout << "The Output matrix is -------- \n\n";

    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}