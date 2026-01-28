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

bool detectCycle(Node *&head)
{
    if (!head)
        return false;
    Node *slow = head;
    Node *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}

int length(Node *head)
{
    int len = 0;
    while (head)
    {
        len++;
        head = head->next;
    }
    return len;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    // Create two linked lists that intersect:
    // List A: 1 -> 2 \
    //                  6 -> 7
    // List B:    3 -> 4 /

    // Shared part
    Node *intersect = new Node(6);
    intersect->next = new Node(7);

    // First list: 1 -> 2 -> 6 -> 7
    Node *headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = intersect;

    // Second list: 3 -> 4 -> 6 -> 7
    Node *headB = new Node(3);
    headB->next = new Node(4);
    headB->next->next = intersect;
    int A = length(headA);
    int B = length(headB);
    if (A > B)
    {
        A--;
        headA = headA->next;
    }
    if (B > A)
    {
        B--;
        headB = headB->next;
    }

    while (headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    if (headA == headB)
    {
        cout << "Yes, Intersaction";
    }
    else
    {
        cout << "No";
    }

    return 0;
}