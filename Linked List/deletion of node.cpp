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
void deleteAthead(node *&head)
{ // deleting node at head
    node *temp = head;
    head = head->next;

    delete (temp);
}
void deletenode(node *&head, int val)
{ // deleteing thr node
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        deleteAthead(head);
        return;
    }
    node *temp = head;
    while (temp->next->data != val)
    { // finding the element to delete
        temp = temp->next;
    }
    node *del = temp->next;        // saving the deleting element
    temp->next = temp->next->next; // shifting the control to next element
    delete (del);
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
    insertAthead(head, 0);
    deletenode(head, 1);
    display(head);
    deleteAthead(head);
    display(head);
    return 0;
}
