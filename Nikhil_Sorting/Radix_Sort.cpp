#include <bits/stdc++.h>

using namespace std;

#define int long long
// To used this, we must have same number of digits, the idea is first sort based on unit place, tens place and all.

/*
 The count array stores cumulative positions. When processing from right to left:

count[(arr[i] / exp) % 10] - 1 gives the correct position for arr[i]
After placing the element, we decrement the count
The next element with the same digit gets placed one position earlier
*/
void counting_sort(vector<int> &arr, int exp)
{
    vector<int> count(10, 0);
    for (int i : arr)
    {
        count[(i / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    int n = arr.size();
    vector<int> res(n);
    for (int i = n - 1; i >= 0; i--)
    {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = res;
}

void Radix(vector<int> &arr)
{
    int max_ele = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_ele / exp > 0; exp *= 10)
    {
        counting_sort(arr, exp);
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
    vector<int> arr = {62, 75, 21, 10, 18, 36};
    // insertion sort
    print(arr);
    Radix(arr);
    print(arr);

    return 0;
}