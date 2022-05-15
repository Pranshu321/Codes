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
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

struct compare
{
    bool operator()(node *first, node *second)
    {
        return first->data > second->data;
    }
};
node *K_sorted(node *head, int k)
{
    if (head == NULL)
    {
        return head;
    }
    priority_queue<node *, vector<node *>, compare> pq; // priority queue.
    node *newhead = NULL, *cur;
    for (int i = 0; i <= k && head != NULL; i++)
    {
        pq.push(head);
        head = head->next;
    }

    while (!pq.empty())
    {

        if (newhead == NULL)
        { // newhead for the sorted.
            newhead = pq.top();
            newhead->prev = NULL;
            cur = newhead;
        }
        else
        {
            cur->next = pq.top(); // Addding the element to the next.
            pq.top()->prev = cur;
            cur = pq.top();
        }

        pq.pop();

        if (head != NULL)
        { // Addding element to queue.
            pq.push(head);
            head = head->next;
        }
    }
    cur->next = NULL;
    return newhead;
}

void insertAtLast(node *&head, int val)
{
    node *t = new node(val);
    if (!head)
    {
        head = t;
        t->prev = NULL;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = t;
    t->prev = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " - >";
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
    insertAtLast(head, 3);
    insertAtLast(head, 6);
    insertAtLast(head, 2);
    insertAtLast(head, 12);
    insertAtLast(head, 56);
    insertAtLast(head, 8);
    display(head);
    node *ans = K_sorted(head, 2);
    display(ans);

    return 0;
}