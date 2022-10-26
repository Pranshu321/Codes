#include <bits/stdc++.h>
using namespace std;
const int N = 1e4;
void count_sort(int a[], int n)
{
    int k = a[0];
    int count[N] = {0};
    for (int i = 0; i < n; i++)
    {
        k = max(k, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    } // this will gives the position of the number in // array
    int out[n];
    for (int i = n - 1; i >= 0; i--)
    {
        out[--count[a[i]]] = a[i];
    } // decresing by one to get actual position in // array and then put the element,
    for (int i = 0; i < n; i++)
    {
        a[i] = out[i];
    }
}
int32_t main()
{
    // your code goes here
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    count_sort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
