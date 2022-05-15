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
int min_ele = 0;

void Pop()
{
    if (s.empty())
    {
        return;
    }
    else
    {
        if (s.top() < min_ele)
        {
            min_ele = (2 * min_ele) - s.top();
            s.pop();
        }
        else
        {
            s.pop();
        }
    }
}

void Push(int a)
{
    if (s.empty())
    {
        s.push(a);
        min_ele = a;
    }
    else
    {
        if (a >= min_ele)
        {
            s.push(a);
        }
        else if (a < min_ele)
        {
            s.push((2 * a) - min_ele);
            min_ele = a;
        }
    }
}

int minimum()
{
    if (s.empty())
    {
        return -1;
    }
    return min_ele;
}

int Top()
{
    if (s.empty())
    {
        return -1;
    }
    else
    {
        if (s.top() < min_ele)
        {
            return ((2 * min_ele) - s.top());
        }
        else
        {
            return s.top();
        }
    }
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Push(3);
    Push(5);
    cout << "The minimum element " << minimum() << endl;
    Push(2);
    Push(1);
    cout << "The minimum element " << minimum() << endl;
    Pop();
    cout << "The minimum element " << minimum() << endl;
    // cout << "The top element in stack is : " << Top() << endl;
    Pop();
    // cout << "The minimum element After popping : " << minimum()<< endl;
    cout << "The top element in stack is : " << Top();

    return 0;
}