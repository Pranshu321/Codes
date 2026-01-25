#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    vector<int> arr = {3, 0, 2, 1, 2};
    int idx = 2;
    queue<int> q;
    q.push(idx);
    bool flag = false;
    int sz = arr.size();
    set<int> s;
    s.insert(idx);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto x = q.front();
            q.pop();
            if (arr[x] == 0)
            {
                cout << "Yes, we can reach";
                return 0;
            }
            if (x + arr[x] < n and s.find(x + arr[x]) == s.end())
            {
                q.push(arr[x + arr[x]]);
                s.insert(x + arr[x]);
            }
            if (x - arr[x] >= 0 and s.find(x - arr[x]) == s.end())
            {
                q.push(arr[x - arr[x]]);
                s.insert(x + arr[x]);
            }
        }
    }
    cout << "No, We cant reach";

    return 0;
}