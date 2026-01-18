#include <bits/stdc++.h>

using namespace std;

#define int long long

void deletemid(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    deletemid(s, k-1);
    s.push(val);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(2);
    s.push(6);

    deletemid(s, s.size() / 2 + 1);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}