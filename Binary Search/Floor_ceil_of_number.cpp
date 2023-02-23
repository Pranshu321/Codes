#include <bits/stdc++.h>

using namespace std;

#define ll long long int
int floooor(int a[], int n, int num)
{
    int start = 0, end = n - 1, res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (a[mid] == num)
        {
            return a[mid];
        }
        else if (a[mid] < num) // here we saving nearest smaller element , which is nearest to our number "num"
        {
            res = a[mid];
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return res;
}
int Ceil(int a[], int n, int num)
{
    int start = 0, end = n - 1, res = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (a[mid] == num)
            return a[mid];
        else if (a[mid] < num)
        {
            start = mid + 1;
        }
        else
        {
            res = a[mid]; // saving the number which is lesser than the target element and nearest also .
            end = mid - 1;
        }
    }
    return res;
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
    int f = floooor(a, n, temp);
    int c = Ceil(a, n, temp);
    cout << "The floor of number is : " << f;
    cout << endl;
    cout << "The ceil of number is : " << c;

    return 0;
}