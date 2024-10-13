#include <bits/stdc++.h>

using namespace std;

#define int long long

int AreAll9s(int *num, int n)
{
    int i;
    for (i = 0; i < n; ++i)
        if (num[i] != 9)
            return 0;

    return 1;
}

void generateNextPallindrome(int *num, int n)
{
    int mid = n / 2;
    bool leftSmaller = false;
    int i = mid - 1;
    int j = (n % 2) ? mid + 1 : mid;
    while (i >= 0 and num[i] == num[j])
    {
        i--;
        j++;
    }
    if (i < 0 || num[i] < num[j])
    {
        leftSmaller = true;
    }
    while (i >= 0)
    {
        num[j] = num[i];
        j++;
        i--;
    }
    if (leftSmaller)
    {
        int carry = 1;
        i = mid - 1;
        if (n % 2 == 1)
        {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else
        {
            j = mid;
        }
        while (i >= 0)
        {
            num[i] += carry;
            carry += num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
    }
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int n;
    cin >> n;
    int num[n];
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    if (AreAll9s(num, n))
    {
        cout << 1 << " ";
        for (int i = 1; i < n; i++)
        {
            cout << 0 << " ";
        }
        cout << 1;
    }
    else
    {
        generateNextPallindrome(num, n);
        for (int i = 0; i < n; i++)
        {
            cout << num[i] << " ";
        }
    }

    return 0;
}