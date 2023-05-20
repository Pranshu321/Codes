#include <bits/stdc++.h>
using namespace std;
void swap(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
int parition(int a[], int l, int r)
{
    int pivot = a[r];
    int j = l;
    for(int i=l;i<r-1;i++){
        if(a[i]<=pivot){
            swap(a[i],a[j]);
            j++;
        }
    }
    swap(a[j],a[r]);
    return pivot;
}
void quicksort(int a[], int l, int r)
{
    if (l < r)
    {
        int pi = parition(a, l, r);
        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, r);
    }
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    int a[] = {5, 4, 3, 2, 1};
    quicksort(a, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}
