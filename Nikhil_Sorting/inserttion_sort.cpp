#include <bits/stdc++.h>

using namespace std;

#define int long long

void insertion(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int pos = i - 1;
        while(pos>=0 and arr[pos]>=key){
            arr[pos+1]=arr[pos];
            pos--;
        }
        arr[pos + 1] = key;
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
    insertion(arr);
    print(arr);

    return 0;
}