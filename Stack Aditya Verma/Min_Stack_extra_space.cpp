#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
stack<int> s;
stack<int> ss; // Supporting Stack

void Push(int a)
{
    s.push(a);
    if (ss.empty() || ss.top() >= a)
    {
        ss.push(a);
    }
    return;
}

int minimum()
{
    if (ss.empty())
    {
        return -1;
    }
    return ss.top();
}

int Poping()
{
    if (s.empty() || ss.empty())
    {
        return -1;
    }
    int ans = s.top();
    s.pop();
    if (ss.top() == ans)
    {
        ss.pop();
    }
    return ans;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Push(10);
    Push(9);
    Push(34);
    Push(11);
    Push(1);
    cout << "The minimum element before popping : " << minimum() << endl;
    Poping();
    cout << "After Popping min element is : " << minimum();

    return 0;
}