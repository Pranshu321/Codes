#include <bits/stdc++.h>

using namespace std;

#define int long long

void display(set<int> s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(9);
    s.insert(5);
    s.insert(6);
    s.insert(4);
    cout << *(s.find(0)) << endl;
    s.erase(s.find(4));
    display(s);
    return 0;
}