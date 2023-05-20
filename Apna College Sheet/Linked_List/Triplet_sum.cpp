#include <bits/stdc++.h>

using namespace std;

#define int long long

class Node
{
public:
    int data;
    Node *next;
};

/* A utility function to insert
a node at the beginning of a
linked list*/
void push(Node **head_ref, int new_data)
{
    /* allocate node */
    Node *new_node = new Node();

    /* put in the data */
    new_node->data = new_data;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void isSumSorted(Node *headA, Node *headB, Node *headC, int givenNumber)
{
    Node *a = headA;
    while (a != NULL)
    {
        Node *b = headB;
        Node *c = headC;
        while (b != NULL and c != NULL)
        {

            int sum = a->data + b->data + c->data;
            if (sum == givenNumber)
            {
                cout << "Triplet Found : " << a->data << " " << b->data << " " << c->data << endl;
                break;
            }
            else if (sum < givenNumber)
            {
                b = b->next;
            }
            else
            {
                c = c->next;
            }
        }
        a = a->next;
    }
    cout << "No Triplet Found" << endl;
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Node *headA = NULL;
    Node *headB = NULL;
    Node *headC = NULL;

    /*create a linked list 'a' 10->15->5->20 */
    push(&headA, 20);
    push(&headA, 4);
    push(&headA, 15);
    push(&headA, 10);

    /*create a sorted linked list 'b' 2->4->9->10 */
    push(&headB, 10);
    push(&headB, 9);
    push(&headB, 4);
    push(&headB, 2);

    /*create another sorted
    linked list 'c' 8->4->2->1 */
    push(&headC, 1);
    push(&headC, 2);
    push(&headC, 4);
    push(&headC, 8);

    int givenNumber = 25;

    isSumSorted(headA, headB, headC, givenNumber);

    return 0;
}