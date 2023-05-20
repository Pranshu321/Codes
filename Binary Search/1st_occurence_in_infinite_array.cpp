#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int binary(int a[], int start, int end, int num)
{
    int res = 0;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
        {
            res = mid;
            end = mid - 1;
        }
        if (a[mid] < num)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return res + 1;
}
int searching(int a[], int n, int temp)
{
    int low = 0;
    int high = 1;
    while (temp > a[high])
    {
        low = high;
        high = high * 2;
    }
    return binary(a, low, high, temp);
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
    int temp;
    cin >> temp;
    cout << "The 1st is at position : " << searching(a, n, temp);

    return 0;
}