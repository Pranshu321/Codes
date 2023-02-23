#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int minimum_difference(int a[], int n, int num)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
        {
            return (a[mid] - num);
        }
        else if (a[mid] < num)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return (min(abs(a[end] - num), abs(a[start] - num))); // at the end of the loop if the element is not present the start,end both pointers will point to the two nearest neighbour of the element which we have to find .
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
    cout << "The minimum diffrence is : " << minimum_difference(a, n, temp);

    return 0;
}