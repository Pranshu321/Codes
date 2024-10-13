#include <bits/stdc++.h>

using namespace std;

#define int long long

bool help(int i, int bucket, int bucketsum, int reqsum, int k, vector<int> &nums, vector<int> &picked)
{
    if (bucket >= k)
        return true;
    if (bucketsum == reqsum)
    {
        return help(0, bucket + 1, 0, reqsum, k, nums, picked);
    }
    if (bucketsum > reqsum)
        return false;
    if (i >= nums.size())
        return true;
    if (picked[i])
    {
        return help(i + 1, bucket, bucketsum, reqsum, k, nums, picked);
    }
    else
    {
        // To pick
        picked[i] = true;
        bucketsum += nums[i];
        bool op1 = help(i + 1, bucket, bucketsum, reqsum, k, nums, picked);

        // skip
        picked[i] = false;
        bucketsum -= nums[i];
        bool op2 = help(i + 1, bucket, bucketsum, reqsum, k, nums, picked);

        // return false
        return op1 | op2;
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = accumulate(a.begin(), a.end(), 0);
    vector<int> picked(n, false);
    if (sum % k != 0)
    {
        cout << "false" << endl;
        return 0;
    }
    bool ans = help(0, 0, 0, sum / k, k, a, picked);
    if (ans)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}