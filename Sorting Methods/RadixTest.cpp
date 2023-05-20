#include <bits/stdc++.h>

using namespace std;

#define int long long

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

void insert(node *&head, int n)
{
    if (head == NULL)
    {
        head = new node(n);
        return;
    }
    node *t = head;
    while (t->next != NULL)
    {
        t = t->next;
    }
    t->next = new node(n);
}

int digits(int n)
{
    int count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return count;
}

int del(node *&head)
{
    if (head == NULL)
    {
        return 0;
    }
    node *t = head;
    int val = head->data;
    head = head->next;
    delete t;
    return val;
}

void radix_sort(int a[], int n){
    int mx = *max_element(a, a + n);
    int d = digits(mx);
    node **bins;
    bins = new node *[10];
    for(int i=0;i<10;i++){
        bins[i]=NULL;
    }

    for(int i=0;i<d;i++){
        for(int j=0;j<n;j++){
            insert(bins[(a[j]/(int)pow(10,i))%10],a[j]);
        }
        int x=0,y=0;
        while(x<10){
           while(bins[x]!=NULL){
             a[y++] = del(bins[x]);
            //  bins[x] = bins[x]->next;
           }
           x++;
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int32_t main()
{
    int a[] = {3, 5, 1, 43, 56, 76};
    cout << "Before Sorting \n";
    print(a, 6);
    radix_sort(a, 6);
    cout << "After Radix Sort \n";
    print(a, 6);
    return 0;
}