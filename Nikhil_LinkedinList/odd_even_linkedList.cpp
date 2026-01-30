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

Node *Odd_Even(Node *&head)
{
    Node *odd = head;
    Node *evenHead = head->next;
    Node *even = head->next;
    while ((even and even->next) and (odd and odd->next))
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

// Example usage
int main()
{
    Node *head = nullptr;
    head = insertNode(head, 10, 0); // 10
    head = insertNode(head, 20, 1); // 10 20
    head = insertNode(head, 15, 1); // 10 15 20
    head = insertNode(head, 5, 0);  // 5 10 15 20
    head = insertNode(head, 15, 4); // 5 10 15 20 15
    head = insertNode(head, 10, 5); // 5 10 15 20 15 10
    head = insertNode(head, 5, 6);  // 5 10 15 20 15 10 5
    printList(head);
    Node *t = Odd_Even(head);
    printList(t);
    return 0;
}