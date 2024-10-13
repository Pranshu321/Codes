#include <bits/stdc++.h>

using namespace std;

#define int long long

// input : (**)
// Output: Yes , 1

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    string s;
    cin >> s;
    stack<char> st;
    int starts = 0;
    int balanced = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' or s[i] == '[' or s[i] == '{')
        {
            st.push(s[i]);
            balanced = true;
        }
        if (!st.empty())
        {
            if (s[i] == '}')
            {
                if (st.top() == '{')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (s[i] == ']')
            {
                if (st.top() == '[')
                {
                    st.pop();
                    continue;
                }
                else
                {
                    break;
                }
            }
            if (s[i] == '*')
            {
                if (s[i + 1] == '*')
                {
                    if (st.top() == '(' || st.top() == '[' || st.top() == '{')
                    {
                        starts++;
                    }
                }
            }
        }
        else if (balanced)
        {
            balanced = false;
            break;
        }
    }
    if (st.empty() and balanced)
    {
        cout << "Yes " << starts;
    }
    else
    {
        cout << "No " << starts;
    }

    return 0;
}