#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void print(stack<int> a)
{
    while (!a.empty())
    {
        cout << a.top() << " ";
        a.pop();
    }
}
void inserti(stack<int> &s, int temp)
{
    if (s.empty() || s.top() >= temp)
    {
        s.push(temp);
        return;
    }
    int x = s.top();
    s.pop();
    inserti(s, temp);
    s.push(x);
}

void sorting(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int temp = s.top();
    s.pop();
    sorting(s);
    inserti(s, temp);
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        s.push(a);
    }
    cout << "\nBefore Sorting : ";
    print(s);
    cout << "\nAfter Sotring : ";
    sorting(s);
    print(s);

    return 0;
}