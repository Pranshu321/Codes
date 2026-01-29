#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Lstack
{
    Node *head = NULL;

public:
    void insert(int val)
    {
        if (!head)
        {
            head = new Node(val);
            return;
        }
        Node *n = new Node(val);
        n->next = head;
        head = n;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    int top()
    {
        if (!head)
            return -1;
        return head->data;
    }

    bool isEmpty()
    {
        if (head)
            return true;
        return false;
    }

    void pop()
    {
        if (!head)
        {
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
};

int32_t
main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    auto st = Lstack();
    st.insert(1);
    st.insert(2);
    st.print();
    st.insert(3);
    st.print();
    cout<<st.top()<<"\n";
    st.pop();
    st.print();

    return 0;
}