#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
bool people[11][101];
void check(int n)
{
    string s;
    cin.ignore(); // Buffer cleaning.
    for (int i = 0; i < n; i++)
    {
        getline(cin, s); // getting string.
        stringstream in(s);
        int a;
        while (in >> a)
        {
            people[i + 1][a] = 1;
        }
    }
}

ll dp[101][1 << 12];
string s1, s2;

ll solve(int shirt, int mask, int n)
{
    if (mask == ((1 << n) - 1)) // It is when all shirts are onwed or wear by persons.
        return 1;

    if (shirt > 100) // Shirts out of stock.
    {
        return 0;
    }
    if (dp[shirt][mask] != -1)
    {
        return dp[shirt][mask];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((mask & (1 << (i - 1))) != 0) // Checking the bit is shirt is wear by anyone or not.
            continue;
        if (people[i][shirt])
        {
            int temp_mask = (mask | (1 << (i - 1)));            // Creating the mask for ith shirt.
            ans = (ans + solve(shirt + 1, temp_mask, n)) % mod; // And adding to answer
        }
    }
    ans = (ans + solve(shirt + 1, mask, n)) % mod; // not assingned T-shirt to guy.  
    return dp[shirt][mask] = ans;
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(people, 0, sizeof(people));
        memset(dp, -1, sizeof(dp));
        check(n);
        cout << solve(1, 0, n) << "\n";
    }

    return 0;
}