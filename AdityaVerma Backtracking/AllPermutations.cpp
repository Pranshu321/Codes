#include <bits/stdc++.h>

using namespace std;

#define int long long

void recurPermutations(string s, string out)
{
    if (s.size() == 0)
    {
        cout << out << " ";
        return;
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        if (mp.find(s[i]) == mp.end())
        {
            mp[s[i]] = 1;

            char ch = s[i];
            string ros = s.substr(0, i) + s.substr(i + 1);
            recurPermutations(ros, out + ch);
        }
    }
}

void permutations(int index, string s)
{
    if (index == s.size())
    {
        cout << s << endl;
        return;
    }
    for (int i = index; i < s.size(); i++)
    {
        swap(s[i], s[index]);
        permutations(index + 1, s);
        swap(s[i], s[index]);
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    recurPermutations(s, "");

    return 0;
}