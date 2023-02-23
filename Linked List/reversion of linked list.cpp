#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
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
node *reverse(node *&head) // iterative method for reverse;
{
    node *pre = NULL;
    node *cur = head;
    node *nex;
    while (cur != NULL)
    {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    return pre;
}
node *reverse_recur(node *&head)
{
    {
        if (head == NULL || head->next == NULL)
            return head;
    }
    node *newhead = reverse_recur(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}
void insertAthead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout << "NULL"
         << "\n";
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    node *head = NULL;
    insertAtlast(head, 1);
    insertAtlast(head, 2);
    insertAtlast(head, 3);
    insertAtlast(head, 4);
    display(head);
    // node*newhead1=reverse_recur(head);
    // cout<<"reverse recurssion method"<<"\n";
    // display(newhead1);
    node *newhead2 = reverse(head);
    display(newhead2);
    return 0;
}
