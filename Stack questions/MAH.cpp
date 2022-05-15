#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

int MAH(int a[], int n)
{
    int i = 0, ans = 0;
    // a[n] = 0;
    stack<int> s;
    while (i < n)
    {
        while (!s.empty() && a[s.top()] > a[i]) // this will check that stack top is longest or not and pop it till top became less than vector element or became empty;
        {
            int tp = s.top();
            int height = a[tp];
            s.pop();

            if (s.empty()) // if empty the i reperesent the base and top elemrnt height
            {
                ans = max(ans, height * i);
            }
            else
            {
                int len = i - s.top() - 1; // one back element is the required length;
                ans = max(ans, height * len);
            }
        }
        s.push(i);
        i++;
    }
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "The maximum area in histogram is : " << MAH(a, n);

    return 0;
}