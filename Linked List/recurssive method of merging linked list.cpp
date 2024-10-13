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
node *recursivemerge(node *&head1, node *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *ans;
    if (head1->data < head2->data)
    {
        ans = head1;
        ans->next = recursivemerge(head1->next, head2);
    }
    else
    {
        ans = head2;
        ans->next = recursivemerge(head1, head2->next);
    }
    return ans;
}

node *merge(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;
    node *dummynode = new node(-1);
    node *ptr3 = dummynode;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }
    while (ptr1 != NULL)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }
    while (ptr2 != NULL)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }
    return (dummynode->next);
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
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    node *head1 = NULL;
    node *head2 = NULL;
    insertAthead(head1, 1);
    insertAtlast(head1, 2);
    insertAtlast(head1, 3);
    insertAtlast(head1, 4);
    insertAtlast(head2, 5);
    insertAtlast(head2, 6);
    insertAtlast(head2, 7);
    insertAtlast(head2, 8);
    display(head1);
    display(head2);
    node *newhead = recursivemerge(head1, head2);
    display(newhead);
    // insertAtlast(head1,9);
    // node*newhead1=recursivemerge(head1,head2);
    // display(newhead1);
    return 0;
}
