#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(map<string, string> dataset)
{
    map<string, string> mp;

    for (auto i : dataset)
    {
        mp[i.second] = i.first;
    }

    string start;
    for (auto i : dataset)
    {
        if (mp.find(i.first) == mp.end())
        {
            start = i.first;
            break;
        }
    }

    if (start.empty())
    {
        cout << "Invalid Input";
    }
    auto i = dataset.find(start);
    while (i != dataset.end())
    {
        cout << i->first << "->" << i->second << "\n";
        i = dataset.find(i->second);
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    map<string, string> dataSet;
    dataSet["Chennai"] = "Banglore";
    dataSet["Bombay"] = "Delhi";
    dataSet["Goa"] = "Chennai";
    dataSet["Delhi"] = "Goa";

    solve(dataSet);

    return 0;
}