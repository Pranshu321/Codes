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
void insertAthead(node *&root, int val)
{
    node *n = new node(val);
    if (root == NULL)
    {
        n->next = n;
        root = n;
    }
    // node*n=new node(val);
    node *temp = root;
    while (temp->next != root)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = root;
    root = n;
}
void insertAtlast(node *&root, int val)
{
    if (root == NULL)
    {
        insertAthead(root, val);
        return;
    }
    node *n = new node(val);
    node *temp = root;
    while (temp->next != root)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = root;
}
void deleteAthead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    node *todel = head;
    temp->next = head->next;
    head = head->next;
    delete (todel);
}
void Deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAthead(head);
        return;
    }
    int count = 1;
    node *temp = head;
    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *todel = temp->next;
    temp->next = temp->next->next;
    delete (todel);
}
void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "head"
         << "\n";
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    node *root = NULL;
    insertAtlast(root, 1);
    insertAtlast(root, 2);
    insertAtlast(root, 3);
    insertAtlast(root, 4);
    insertAtlast(root, 5);
    insertAthead(root, 0);
    Deletion(root, 3);
    Deletion(root, 1);
    display(root);

    return 0;
}