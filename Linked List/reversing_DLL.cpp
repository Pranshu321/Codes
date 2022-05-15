#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
struct node
{
    int data;
    node *next, *prev;
    node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

node *reversi(node *&head)
{
    node *cur = head;
    if (cur == NULL && cur->next == NULL)
    {
        return head;
    }
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    head = cur;
    cur->next = cur->prev;
    cur->prev = NULL;
    cur = cur->next;
    while (cur->prev != NULL)
    {
        node *temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;
        cur = cur->next;
    }
    cur->prev = cur->next;
    cur->next = NULL;
    return head;
}
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtlast(node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *n = new node(val);
    node *cur = head;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = n;
    n->prev = cur;
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ->";
        head = head->next;
    }
    cout << "NULL"
         << "\n";
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *head = NULL;

    insertAtlast(head, 10);
    insertAtlast(head, 20);
    insertAtlast(head, 30);
    insertAtlast(head, 40);
    insertAtlast(head, 50);
    insertAtlast(head, 60);
    display(head);
    display(reversi(head));

    return 0;
}