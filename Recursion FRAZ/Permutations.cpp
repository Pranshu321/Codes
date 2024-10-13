#include <bits/stdc++.h>

using namespace std;

#define int long long

void perm(vector<int> &a, int idx)
{
    if (idx >= a.size())
    {
        for (auto i : a)
        {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    unordered_map<int, int> mp;
    for (int i = idx; i < a.size(); i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = 1;
            swap(a[i], a[idx]);
            perm(a, idx + 1);
            swap(a[i], a[idx]);
        }
    }
}

void permutations(vector<int> &a, int idx, vector<int> &temp)
{
    if (temp.size() == a.size())
    {
        for (int i : temp)
        {
            cout << i << " ";
        }
        cout << endl;
        // return;
    }
    unordered_map<int, int> mp;

    for (int i = 0; i < a.size(); i++)
    {
        if (mp.find(a[i]) == mp.end())
        {
            mp[a[i]] = 1;
            temp.push_back(a[i]);
            permutations(a, i + 1, temp);
            temp.pop_back();
            mp.erase(a[i]);
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> temp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "=================================== \n";
    // permutations(a, 0, temp);
    perm(a, 0);

    return 0;
}