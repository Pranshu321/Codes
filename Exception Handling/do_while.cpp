#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    int a, b, c, avg = 0;
    char ch;
    do
    {
        printf("Enter the numbers : ");
        cin >> a >> b >> c;

        int avg = (a + b + c) / 3;
        printf("Average is %d \n", avg);

        printf("Do you want to continue (Y/N) : ");
        cin >> ch;
        cout << "\n";
    } while (ch == 'Y' || ch == 'y');

    return 0;
}