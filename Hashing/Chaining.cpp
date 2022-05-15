#include <bits/stdc++.h>
#include "chains.h"
using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
void Hash_insert(node *HT[], int key)
{
    int index = (key % 10);
    insert(HT[index], key);
}
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    node *HT[10];
    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        Hash_insert(HT, x);
    }
    int key;
    cin >> key;
    if (link_search(HT[(key % 10)], key))
    {
        cout << "Yes Found Hashing Successful :) ";
    }
    else
    {
        cout << "Hashing not successful :( ";
    }

    return 0;
}