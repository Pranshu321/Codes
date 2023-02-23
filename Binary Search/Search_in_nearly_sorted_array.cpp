#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int searching(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if ((a[mid] == num))
            return mid;
        if ((a[mid + 1] == num) && (mid + 1 <= end)) // checking the outerbound condition also that it will not go after size n
            return mid + 1;
        if ((a[mid - 1] == num) && (mid - 1 >= start)) // checking the outerbound condition also that will not go below 0 index
            return mid - 1;
        if (a[mid] < num)
        {
            start = mid + 2;
        }
        else
            end = mid - 2;
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
    cout << "The no. is at position : " << searching(a, n, temp);

    return 0;
}