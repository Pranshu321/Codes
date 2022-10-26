#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

bool isSafe(int row, int col, vector<bool> rows, int n, vector<bool> left_daigonals, vector<bool> right_daigonals)
{

    if (rows[row] == true || left_daigonals[row + col] == true || right_daigonals[col - row + n - 1] == true)
    {
        return false;
    }
    return true;
}

bool solve(vector<vector<int>> &board, int col, int n, vector<bool> &rows, vector<bool> &left_daigonals, vector<bool> &right_daigonals)
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, rows, n, left_daigonals, right_daigonals))
        {
            rows[i] = true;
            left_daigonals[col + i] = true;
            right_daigonals[col - i + n - 1] = true;
            board[i][col] = 1;

            if (solve(board, col + 1, n, rows, left_daigonals, right_daigonals))
            {
                return true;
            }

            rows[i] = false;
            left_daigonals[i + col] = false;
            right_daigonals[col - i + n - 1] = false; // This is formula for checking that is there any queen in its right daigonal.
            board[i][col] = 0;
        }
    }
    return false;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int N;
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    vector<bool> rows(N, false);

    // arrays to tell which diagonals are occupied
    vector<bool> left_digonals(2 * N - 1, false);
    vector<bool> Right_digonals(2 * N - 1, false);

    bool ans = solve(board, 0, N, rows, left_digonals, Right_digonals);

    if (ans == true)
    {
        for (auto i : board)
        {
            /* code */
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Solution Does not Exist\n";
    }

    return 0;
}