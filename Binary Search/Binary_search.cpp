#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int search_num(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start / 2);
        if (a[mid] == num)
            return mid + 1;
        else if (a[mid] < num)
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
    cout << "The no. is at position : " << search_num(a, n, temp);

    return 0;
}