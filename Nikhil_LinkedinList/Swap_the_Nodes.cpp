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

Node *SwapNodes(Node *&head)
{
    if (!head || !head->next)
        return head;
    
    Node *dummy = new Node(-1);
    Node *dummyhead = dummy;
    dummy->next = head;
    Node *prev = dummy;
    
    while (prev->next && prev->next->next)
    {
        Node *swap1 = prev->next;
        Node *swap2 = prev->next->next;
        
        // Perform the swap
        swap1->next = swap2->next;
        swap2->next = swap1;
        prev->next = swap2;
        
        // Move prev to swap1 (which is now after swap2)
        prev = swap1;
    }
    
    return dummyhead->next;
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
    Node *t = SwapNodes(head);
    printList(t);
    return 0;
}