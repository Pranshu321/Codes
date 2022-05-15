#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define size 10

int hashing(int n)
{
    return n % size;
}

int probe(int a[], int key)
{
    int idx = hashing(key);

    int i = 0;
    while (a[(idx + (i * i)) % size] != 0)
    {
        i++;
    }

    return (idx + (i * i)) % size;
}

void Insert(int a[], int key)
{
    int idx = hashing(key);

    if (a[idx] != 0)
    {
        idx = probe(a, key);
    }
    a[idx] = key;
}

int Search(int a[], int key)
{
    int idx = hashing(key);
    int i = 0;
    while (a[(idx + (i * i)) % size] != key)
    {
        i++;
    }

    return (idx + (i * i)) % size;
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        Insert(a, x);
    }
    int key;
    cin >> key;
    cout << "Key is found at : " << Search(a, key);

    return 0;
}