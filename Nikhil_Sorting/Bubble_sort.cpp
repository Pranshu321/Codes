#include <bits/stdc++.h>

using namespace std;

#define int long long

void bubble(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] >= arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
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
    bubble(arr);
    print(arr);

    return 0;
}