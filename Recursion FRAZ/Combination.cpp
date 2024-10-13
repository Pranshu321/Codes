#include <bits/stdc++.h>

using namespace std;

#define int long long

// Combination - Subsets is pre-requistes
// Select the Size of the subset
void subsets(vector<int> &a, int idx, vector<int> &temp)
{ // This is the size of the subset we want
    if (temp.size() == 2)
    {
        if (temp.size() == 2)
        {
            for (int i : temp)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        return;
    }

    // yeh wo condition hai jismai , jo required element hai vo jada hai remaining se, matlab hum wrong direction mai hai or hame wapas jana hoga.
    if (a.size() - idx + 1 < 2)
    {
        return;
    }

    if (idx >= a.size())
    {
        return;
    }
    temp.push_back(a[idx]);
    subsets(a, idx + 1, temp);
    temp.pop_back();
    subsets(a, idx + 1, temp);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> temp;
    cout << "==========================================\n";
    subsets(a, 0, temp);

    return 0;
}