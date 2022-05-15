#include <bits/stdc++.h>

using namespace std;

#define ll long long int
struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int Find_Middle(node *head)
{
    if (head == NULL)
    {
        return -1;
    }
    node *slow;
    node *fast;
    slow = fast = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow->data;
}

void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertAtlast(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
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

    display(head);
    cout << "Middle element is : " << Find_Middle(head);

    return 0;
}