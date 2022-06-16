#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int search_first(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    int res = INT_MAX;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
        {
            res = min(res, mid);
            end = mid - 1;
        }
        else if (a[mid] < num)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return res + 1;
}
int search_last(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    int res = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
        {
            res = mid;
            start = mid + 1;
        }
        else if (a[mid] < num)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return res + 1;
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
    cout << "The first occurence is : " << search_first(a, n, num);
    cout << endl;
    cout << "The last occurence is : " << search_last(a, n, num);

    return 0;
}