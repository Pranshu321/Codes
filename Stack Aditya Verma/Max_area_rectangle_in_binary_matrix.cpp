#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int a[10001][10001];

int MAH(vector<int> v)
{
    int i = 0, area = 0, n = v.size();
    stack<int> st;
    while (i < n)
    {
        if (st.empty() || v[st.top()] < v[i]) // This is when we have not consider that block 
        {
            st.push(i++);
        }
        else  // When we have to consider the block then check that stack empty empty if simply find area .
        {
            int curr = st.top();
            int h = v[curr];
            st.pop();
            int ar;
            if (st.empty())
                ar = h * i;
            else
                ar = h * (i - st.top() - 1);
            area = max(area, ar);
        }
    }
    while (!st.empty())
    {
        int curr = st.top();
        int h = v[curr];
        st.pop();
        int ar;
        if (st.empty())
            ar = h * i;
        else
            ar = h * (i - st.top() - 1);
        area = max(area, ar);
    }
    return area;
}
int maxrectangle(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> a(m, 0);
    int max_ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                a[j] = 0;
            }
            else
            {
                a[j] = a[j] + 1;
            }
        }
        int curans = MAH(a);
        max_ans = max(max_ans, curans);
    }
    return max_ans;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            row.push_back(x);
        }
        v.push_back(row);
    }
    cout << "The maximum area is : " << maxrectangle(v);

    return 0;
}