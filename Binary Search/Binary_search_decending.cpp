#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int search_desen(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
            return mid + 1;
        else if (a[mid] < num)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int num;
    cin >> num;
    cout << "The number is position : " << search_desen(a, n, num);

    return 0;
}