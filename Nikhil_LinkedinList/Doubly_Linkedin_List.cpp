#include <bits/stdc++.h>

using namespace std;

#define int long long

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

Node *insert(Node *&head, int val)
{
    if (!head)
    {
        return NULL;
    }
    Node *t = head;
    while (t->next)
    {
        t = t->next;
    }
    Node *n = new Node(val);
    t->next = n;
    n->prev = t;
    return head;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
    cout << endl;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Node *head = new Node(5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    insert(head, 9);
    print(head);

    return 0;
}