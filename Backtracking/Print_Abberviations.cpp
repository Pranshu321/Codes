#include <bits/stdc++.h>

using namespace std;

#define int long long

void printAbbr(string s, string ans, int count, int pos)
{
    if (pos == s.length())
    {
        if (count == 0)
        {
            cout << ans << "\n";
        }
        else
        {
            cout << ans + to_string(count) << endl;
        }
        return;
    }

    // here we are adding the count till far to the ans string and then printing the ans string with count till far and pos incremented
    // by 1 to print the abbreviation of the string s[pos] with count till far.

    if (count > 0)
        printAbbr(s, ans + to_string(count) + s[pos], 0, pos + 1);

    // We are not adding count as the count is zero and pos is incremented
    else
        printAbbr(s, ans + s[pos], 0, pos + 1);

    // We increase the count as we not taken the current char to our answer
    printAbbr(s, ans, count + 1, pos + 1);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;

    printAbbr(s, "", 0, 0);

    return 0;
}