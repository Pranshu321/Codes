#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n = nums.size();
    vector<bool> marked(n, false);
    int score = 0;
    while (true)
    {
        int minimumNumber = INT_MAX, min_idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (!marked[i] && nums[i] < minimumNumber)
            {
                minimumNumber = nums[i];
                min_idx = i;
            }
        }
        if (min_idx == -1)
        {
            break;
        }
        score += minimumNumber;
        marked[min_idx] = true;
        if (check(min_idx))
        {
            marked[min_idx - 1] = true;
        }
        if (min_idx < n - 1)
        {
            marked[min_idx + 1] = true;
        }
    }
    return 0;
}