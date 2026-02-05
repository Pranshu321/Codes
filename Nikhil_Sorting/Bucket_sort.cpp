#include <bits/stdc++.h>

using namespace std;

#define int long long
// it is used where the data is distribution is quite uniform

void insertionSort(vector<int> &bucket)
{
    for (int i = 1; i < bucket.size(); ++i)
    {
        int key=bucket[i];
        int j=i-1;
        while(j>=0 and bucket[j]>key){
            bucket[j+1]=bucket[j];
            j--;
        }
        bucket[j+1]=key;
    }
}

int getBucketIndex(int value, int min_ele, int max_ele, int bucket_size)
{
    return (value - min_ele) * bucket_size / (max_ele - min_ele + 1);
}

void bucket(vector<int> &arr)
{
    int max_ele = *max_element(arr.begin(), arr.end());
    int min_ele = *min_element(arr.begin(), arr.end());
    map<int, vector<int>> mp;

    for (auto i : arr)
    {
        int idx = getBucketIndex(i, min_ele, max_ele, arr.size());
        mp[idx].push_back(i);
    }
    int idx = 0;
    for (auto &i : mp)
    {
        insertionSort(i.second);
        for (auto j : i.second)
        {
            arr[idx++] = j;
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
    bucket(arr);
    print(arr);

    return 0;
}