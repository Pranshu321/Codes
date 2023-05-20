/* C++ program to randomly select a node from a singly
linked list */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

/* Link list node */
class Node
{
public:
    int key;
    Node *next;
    void printRandom(Node *);
    void push(Node **, int);
};

// A reservoir sampling based function to print a
// random node from a linked list
void Node::printRandom(Node *head)
{
    // IF list is empty
    if (head == NULL)
        return;

    // Use a different seed value so that we don't get
    // same result each time we run this program
    srand(time(NULL));

    // Initialize result as first node
    int result = head->key;

    // Iterate from the (k+1)th element to nth element
    Node *current = head;
    int n;
    for (n = 2; current != NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
            result = current->key;

        // Move to next node
        current = current->next;
    }

    cout << "Randomly selected key is \n"
         << result;
}

/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST */

/* A utility function to create a new node */
Node *newNode(int new_key)
{
    // allocate node
    Node *new_node = (Node *)malloc(sizeof(Node));

    /// put in the key
    new_node->key = new_key;
    new_node->next = NULL;

    return new_node;
}

/* A utility function to insert a node at the beginning
of linked list */
void Node::push(Node **head_ref, int new_key)
{
    /* allocate node */
    Node *new_node = new Node;

    /* put in the key */
    new_node->key = new_key;

    /* link the old list of the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

// Driver program to test above functions
int main()
{
    Node n1;
    Node *head = NULL;
    n1.push(&head, 5);
    n1.push(&head, 20);
    n1.push(&head, 4);
    n1.push(&head, 3);
    n1.push(&head, 30);

    n1.printRandom(head);

    return 0;
}

// This code is contributed by SoumikMondal
