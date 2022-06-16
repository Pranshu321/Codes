#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int binary(int a[], int start, int end, int num)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
        {
            return mid + 1;
        }
        else if (a[mid] < num)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
int search_infinite(int a[], int n, int num)
{
    int low = 0;
    int high = 1;
    while (num > a[high])
    { // We increse the value of high till then the value at high will be greater than target value;
        low = high;
        high = high * 2;
    }
    return binary(a, low, high, num);
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
    cout << "The number is at postion : " << search_infinite(a, n, temp);

    return 0;
}