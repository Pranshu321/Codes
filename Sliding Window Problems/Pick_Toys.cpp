#include <bits/stdc++.h>

using namespace std;

// Continous Toys pick karna hai
// 1. Do unique element se jada nahi le sakte
// 2. continous manner mai karna hai

#define int long long

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int i = 0, j = 0, ans = 0;
    int k = 2;
    unordered_map<int, int> mp;
    while (j < n)
    {
        mp[s[j]]++;
        if (mp.size() < k)
        {
            j++;
        }
        else if (mp.size() == k)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else
        {
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }

    cout << "Max Toys John can pick : " << ans;

    return 0;
}