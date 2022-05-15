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
    {   data=val;
        next = prev = NULL;
    }
};

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
int countpairs(node *first, node *last, int val)
{
    int count = 0;

    while (first != NULL && last != NULL && first != last && last->next != first)
    {
        if ((first->data + last->data) == val)
        {
            count++;
            first = first->next;
            last = last->prev;
        }
        else if ((first->data + last->data) > val)
        {
            last = last->prev;
        }
        else
        {
            first = first->next;
        }
    }
    return count;
}
int counttriplets(node *head, int x)
{
    if (head == NULL)
    {
        return 0;
    }
    node *cur, *first, *last;
    int count = 0;
    last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    for (cur = head; cur != NULL; cur = cur->next)
    {
        first = cur->next;

        count += countpairs(first, last, x - cur->data);
    }

    return count;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *head = NULL;
    insertAtlast(head, 2);
    insertAtlast(head, 3);
    insertAtlast(head, 4);
    insertAtlast(head, 5);
    insertAtlast(head, 6);
    insertAtlast(head, 7);
    display(head);
    cout << "Total Triplets are: - " << counttriplets(head,18);

    return 0;
}