#include <bits/stdc++.h>

using namespace std;

#define int long long

void counting(vector<int> &arr)
{
    int n = arr.size();

    int maxval = 0;
    for (int i = 0; i < n; i++)
        maxval = max(maxval, arr[i]);

    vector<int> cntArr(maxval + 1, 0);

    for (int i = 0; i < n; i++)
        cntArr[arr[i]]++;

    for (int i = 1; i <= maxval; i++)
    {
        cntArr[i] += cntArr[i - 1];
    }
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        res[cntArr[arr[i]] - 1] = arr[i];
        cntArr[arr[i]]--;
    }
    arr = res;
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
    counting(arr);
    print(arr);

    return 0;
}