#include <bits/stdc++.h>

using namespace std;

#define int long long

vector<int> merge(const vector<int> &left, const vector<int> &right)
{
    vector<int> res;
    res.reserve(left.size() + right.size());

    size_t l = 0, r = 0;
    while (l < left.size() && r < right.size())
    {
        if (left[l] <= right[r])
            res.push_back(left[l++]);
        else
            res.push_back(right[r++]);
    }
    while (l < left.size())
        res.push_back(left[l++]);
    while (r < right.size())
        res.push_back(right[r++]);

    return res;
}

vector<int> merge_sort(vector<int> &arr, int i, int j)
{
    if (i >= j)
    {
        return {arr[i]};
    }
    int mid = (i + j) / 2;
    auto l = merge_sort(arr, i, mid);
    auto r = merge_sort(arr, mid + 1, j);
    auto ans = merge(l, r);
    return ans;
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
    auto ans = merge_sort(arr, 0, arr.size() - 1);
    print(ans);

    return 0;
}