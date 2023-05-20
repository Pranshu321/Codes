#include <bits/stdc++.h>
using namespace std;
string removeduplicate(string s)
{
    if (s.empty())
    {
        return "";
    }
    char ch = s[0];
    string op = removeduplicate(s.substr(1));
    if (ch == op[0])
    {
        return op;
    }
    return ch + op;
}
int main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout << removeduplicate("aaaabbbbcccddsssee");
    return 0;
}
