#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
bool isvalid(int m[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (m[row][i] == num) // Checking in row
        {
            return false;
        }
        else if (m[i][col] == num) // checking in column
        {
            return false;
        }
        else if (m[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) // checking in matrix of 3x3 or we say part of 9x9 matrix
        {
            return false;
        }
    }
    return true;
}

bool sudoku(int m[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (m[i][j] == 0) // That place is empty or not
            {
                for (int k = 1; k <= 9; k++) // Trying all numbers we dont which can fit
                {
                    if (isvalid(m, i, j, k)) // valid will tell that is this able to fit
                    {
                        m[i][j] = k;

                        if (sudoku(m)) // If our changed matrix gives us true then otherwise backtrack and return false;
                        {
                            return true;
                        }
                        else
                        {
                            m[i][j] = 0; // Backtracking
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int m[9][9];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> m[i][j];
        }
    }

    if (sudoku(m))
    {
        cout << "Yes , Sudoku can be solved";
    }
    else
    {
        cout << "No , Sodoku can't be solved";
    }

    return 0;
}