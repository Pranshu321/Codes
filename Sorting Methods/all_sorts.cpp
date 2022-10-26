/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

void bubb_sort(int a[], int n)
{

    for (int i = 0; i < n - 1; i++)

    {

        for (int j = 0; j < n - 1; j++)

        {

            if (a[j] > a[i + 1])

            {

                swap(a[j], a[i + 1]);
            }
        }
    }
}

void selection_sort(int a[], int n)
{

    int idx = 0;

    for (int i = 0; i < n - 1; i++)

    {

        idx = i;

        for (int j = i + 1; j < n; j++)

        {

            if (a[j] < a[idx])

            {

                idx = j;
            }
        }

        int temp = a[i];

        a[i] = a[idx];

        a[idx] = temp;
    }
}

void

Insertion_sort(int a[], int n)
{

    int key = 0;

    for (int i = 1; i < n; i++)

    {

        key = a[i];

        int j = i - 1;

        while (j >= 0 and a[j] > key)

        {

            a[j + 1] = a[j];

            j--;
        }

        a[j + 1] = key;
    }
}

int partition(int a[], int l, int r)
{

    int pivot = a[r];

    int j = l - 1;

    for (int i = l; i < r; i++)

    {

        if (a[i] < pivot)

        {

            j++;

            swap(a[i], a[j]);
        }
    }

    swap(a[j + 1], a[r]);

    return (j + 1);
}

void quick_sort(int a[], int l, int r)
{

    if (l < r)

    {

        int pivot = partition(a, l, r);

        quick_sort(a, l, pivot - 1);

        quick_sort(a, pivot + 1, r);
    }
}

void

merge(int a[], int l, int mid, int r)
{

    int n1 = mid - l + 1;

    int n2 = r - mid;

    int x[n1], y[n2];

    for (int i = 0; i < n1; i++)

    {

        x[i] = a[l + i];
    }
    for (int i = 0; i < n2; i++)

    {

        y[i] = a[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)

    {

        if (x[i] < y[j])

        {

            a[k] = x[i];

            i++;

            k++;
        }

        else

        {

            a[k] = y[j];

            k++;

            j++;
        }
    }

    while (i < n1)

    {

        a[k] = x[i];

        k++;

        i++;
    }

    while (j < n2)

    {

        a[k] = y[j];

        k++;

        j++;
    }
}

void merge_sort(int a[], int l, int r)
{

    if (l < r)

    {

        int mid = l + (r - l) / 2;

        merge_sort(a, l, mid);

        merge_sort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

void

heapify(int a[], int n, int i)
{

    int largest = i;

    int l = 2 * i + 1;

    int r = 2 * i + 2;

    if (l < n && a[l] > a[largest])

    {

        largest = l;
    }

    if (r < n && a[r] > a[largest])

    {

        largest = r;
    }

    if (largest != i)

    {

        swap(a[i], a[largest]);

        heapify(a, n, largest);
    }
}

void heap_sort(int a[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)

    {

        heapify(a, n, i);
    }

    for (int i = n - 1; i > 0; i--)

    {

        swap(a[0], a[i]);

        heapify(a, i, 0);
    }
}

int

main()
{

    int a[] = {45, 32, 46, 92, 12, 70};

    int n = sizeof(a) / sizeof(a[0]);

    // bubb_sort(a,n);
    // selection_sort(a,n);
    // Insertion_sort(a,n);
    // quick_sort(a,0,n-1);
    //   merge_sort(a,0,n-1);
    heap_sort(a, n);

    for (auto i : a)

    {

        cout << i << " ";
    }

    return 0;
}
