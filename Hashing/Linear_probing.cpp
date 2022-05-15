#include <bits/stdc++.h>

using namespace std;
const int size = 10;
#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int hash_index(int n)
{
    return n % size;
}
int probe(int a[], int key)
{
    int idx = hash_index(key);
    int i = 0;
    while (a[(idx + i) % size] != 0)
    {
        i++;
    }
    return (idx + i) % size;
}
int Insert(int a[], int key)
{
    int idx = hash_index(key);
    if (a[idx] != 0)
    {
        idx = probe(a, key);
    }
    a[idx] = key;
}

int Search(int a[], int key)
{
    int idx = hash_index(key);

    int i = 0;
    while (a[(idx + i) % size] != key)
    {
        i++;
    }
    return (idx + i) % size;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[10]={0};

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Insert(a, x);
    }
    int key;
    cin >> key;

    cout << "Key found at : " << Search(a, key);

    return 0;
}