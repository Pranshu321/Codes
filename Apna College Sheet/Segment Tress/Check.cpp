// You are given N lines in a horizontal line numbered from 1 to N.The height of the i -
//     th line from the left is Ai.For each line(1 <= i N),
//     you will perform either of the following change Ai = Ai once or do nothing.Determine if it is possible to perform the change so that the heights of the lines are
//                                                                         non
//                                                                         - decreasing from left to right.

// code
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool c = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            c = false;
            break;
        }
    }
    if (c)
    {
        cout << "YES";
        return 0;
    }
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            if (flag)
            {
                a[i] = a[i] - 1;
                flag = false;
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}