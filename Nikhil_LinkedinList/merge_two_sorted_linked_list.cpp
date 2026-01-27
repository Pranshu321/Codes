#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert a node at a given position (0-based index)
Node *insertNode(Node *head, int data, int position)
{
    Node *newNode = new Node(data);
    if (position == 0)
    {
        newNode->next = head;
        return newNode;
    }
    Node *curr = head;
    for (int i = 0; curr != nullptr && i < position - 1; ++i)
    {
        curr = curr->next;
    }
    if (curr == nullptr)
    {
        // Position is greater than the length, insert at end
        delete newNode;
        return head;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

// Helper function to print the list
void printList(Node *head)
{
    Node *curr = head;
    while (curr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *deleteNode(Node *&head, int val)
{
    if (!head)
    {
        return NULL;
    }
    if (head->data == val)
    {
        Node *t = head;
        head = head->next;
        delete t;
        return head;
    }
    Node *temp = head;
    while (temp->next and temp->next->data != val)
    {
        temp = temp->next;
    }
    if (!temp->next)
        return NULL;
    Node *del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

Node *mergeLinkedList(Node *&h1, Node *&h2)
{
    if (!h1 or !h2)
    {
        return NULL;
    }
    Node *t = new Node(-1);
    Node *temp = t;
    while (h1 and h2)
    {
        if (h1->data <= h2->data)
        {
            temp->next = h1;
            h1 = h1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = h2;
            h2 = h2->next;
            temp = temp->next;
        }
    }
    while (h1)
    {
        temp->next = h1;
        h1 = h1->next;
        temp = temp->next;
    }
    while (h2)
    {
        temp->next = h2;
        h2 = h2->next;
        temp = temp->next;
    }
    return t->next;
}

// Example usage
int main()
{
    // First sorted linked list
    Node *head1 = nullptr;
    head1 = insertNode(head1, 1, 0);
    head1 = insertNode(head1, 3, 1);
    head1 = insertNode(head1, 5, 2);
    head1 = insertNode(head1, 7, 3);
    head1 = insertNode(head1, 10, 4);
    head1 = insertNode(head1, 11, 5);
    cout << "First sorted list: ";
    printList(head1);

    // Second sorted linked list
    Node *head2 = nullptr;
    head2 = insertNode(head2, 2, 0);
    head2 = insertNode(head2, 4, 1);
    head2 = insertNode(head2, 6, 2);
    head2 = insertNode(head2, 8, 3);
    head2 = insertNode(head2, 9, 4);
    cout << "Second sorted list: ";
    printList(head2);

    auto t = mergeLinkedList(head1, head2);
    printList(t);
    return 0;
}