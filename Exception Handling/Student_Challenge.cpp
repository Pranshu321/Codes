#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
class Overflowexception : public exception
{
};
class Underflowexception : public exception
{
};

class STACK
{
    int *stk;
    int size;
    int top = -1;

public:
    STACK(int sz)
    {
        size = sz;
        stk = new int[size];
    }
    void push(int x)
    {
        if (top == size - 1)
        {
            throw Overflowexception();
        }
        top++;
        stk[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            throw Underflowexception();
        }
        top--;
    }
    void display()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << stk[i] << " ";
        }
        cout << "\n";
    }
};
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    STACK s(n);
    try
    {
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            s.push(a);
        }
        s.display();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.pop();
        s.display();
    }
    catch (Overflowexception e)
    {
        cout << "stack overflowed";
    }
    catch (Underflowexception e)
    {
        cout << "Stack is empty yaar";
    }

    return 0;
}