#ifndef chains_h
#define chains_h
#include <bits/stdc++.h>
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

void insert(node *&root, int val)
{
    node *temp = new node(val);
    if (root == NULL)
    {
        root = temp;
        return;
    }
    node *t = root;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = temp;
}

bool link_search(node *root, int val)
{
    if (root == NULL)
        return false;
    node *temp = root;
    while (temp != NULL)
    {
        if (val == temp->data)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

#endif