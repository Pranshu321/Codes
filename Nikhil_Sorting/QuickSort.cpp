#include <bits/stdc++.h>

using namespace std;

#define int long long

int findparition(vector<int> &arr, int begin, int end)
{
    int pivot = arr[end];
    int idx = begin - 1;
    for (int j = begin; j <= end; j++)
    {
        if (arr[j] < pivot)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    swap(arr[idx + 1], arr[end]);
    return idx + 1;
}

vector<int> quick_sort(vector<int> &arr, int i, int j)
{
    if (i < j)
    {
        int parition = findparition(arr, i, j);
        quick_sort(arr, i, parition - 1);
        quick_sort(arr, parition + 1, j);
    }
}

void print(vector<int> &ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int> arr = {6, 7, 2, 10, 1, 3};
    // insertion sort
    print(arr);
    quick_sort(arr, 0, arr.size() - 1);
    print(arr);

    return 0;
}