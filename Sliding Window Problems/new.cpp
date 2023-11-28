#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSecondsToTarget(vector<int> &nums1, vector<int> &nums2, int x)
{
    int n = nums1.size();

    // Helper function to check if the sum of elements in nums1 is less than or equal to x
    auto isSumLessThanOrEqual = [&](int target)
    {
        long long sum = 0;
        for (int i = 0; i < n; ++i)
        {
            long long curr = nums1[i] + 1LL * nums2[i] * target; // Increment by nums2[i] for 'target' seconds
            sum += min(curr, static_cast<long long>(x));
        }
        return sum <= x;
    };

    // Binary search to find the minimum time to reach the target sum
    int left = 1;
    int right = 1e9; // Maximum possible time (adjust this based on constraints)
    int result = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (isSumLessThanOrEqual(mid))
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 2, 1};
    int x = 7;

    int result = minSecondsToTarget(nums1, nums2, x);
    cout << "Minimum time needed to make the sum <= x: " << result << endl;

    return 0;
}
