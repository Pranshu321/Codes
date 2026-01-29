#include <bits/stdc++.h>

using namespace std;

#define int long long

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

int detectCycle(Node *&head)
{
    if (!head)
        return 0;
    Node *slow = head;
    Node *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            fast = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast->data;
        }
    }
    return -1;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // Create a cyclic linked list: 1 -> 2 -> 3 -> 4 -> 2 (cycle starts at node with value 2)
    Node *head = nullptr;
    head = insertNode(head, 4, 0);
    head = insertNode(head, 3, 0);
    head = insertNode(head, 2, 0);
    head = insertNode(head, 1, 0);

    // Creating a cycle: connect last node (4) to node with value 2
    Node *curr = head;
    Node *cycleStart = nullptr;
    while (curr->next != nullptr)
    {
        if (curr->data == 2)
            cycleStart = curr;
        curr = curr->next;
    }
    curr->next = cycleStart; // Introduce cycle
    cout << detectCycle(head);

    return 0;
}