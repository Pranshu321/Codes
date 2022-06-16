#include <bits/stdc++.h>
using namespace std;

bool issafe(vector<vector<int>> &arr, int row, int col, int n)
{
    int dupcol = col;
    int duprow = row;

    for (int i = 0; i < row; i++)
    {
        if (arr[i][col] == 1)
        {
            return false;
        }
    }
    row = duprow;
    col = dupcol;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
            return false;
        row--;
        col++;
    }

    return true;
}

bool queen_place(vector<vector<int>> &arr, int row, int n)
{
    if (row >= n)
    {
        return true;
    }
    for (int col = 0; col < n; col++)
    {
        if (issafe(arr, row, col, n))
        {
            arr[row][col] = 1;
            if (queen_place(arr, row + 1, n))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    if (queen_place(arr, 0, n))
    {
        for (auto i : arr)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << "No , possible queen placing";
    }

    return 0;
}
