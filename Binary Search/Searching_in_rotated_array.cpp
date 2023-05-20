#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int binary(int a[], int start, int end, int num)
{
    int low = start, high = end;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == num)
            return mid + 1;
        else if (a[mid] < num)
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}
int rotations(int a[], int n)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (a[mid] <= a[next] && a[mid] <= a[prev])
        {
            return mid;
        }
        else if (a[start] <= a[mid])
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
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
    int temp;
    cin >> temp;
    int res = rotations(a, n);
    int pos1 = binary(a, 0, res - 1, temp);
    int pos2 = binary(a, res, n - 1, temp);
    if (pos1 == -1 && pos2 == -1)
        cout << "The number is at position : " << pos1;
    else if (pos1 != -1)
    {
        cout << "The number is at position : " << pos2;
    }
    else
        cout << "The number is at position : " << pos2;

    return 0;
}