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
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int sum1 = 0, sum2 = 0, sum3 = 0;

    int s1[n1], s2[n2], s3[n3];
    for (int i = 0; i < n1; i++)
    {
        cin >> s1[i];
        sum1 += s1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> s2[i];
        sum2 += s2[i]; 
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> s3[i];
        sum3 += s3[i];
    }
    int top1 = 0, top2 = 0, top3 = 0;
    int ans = 0;
    while (true)
    {
        if (top1 == n1 or top2 == n2 or top3 == n3)
        {
            ans = 0;
            break;
        }
        else if (sum1 == sum2 and sum2 == sum3)
        {
            ans = sum1;
            break;
        }
        else if (sum1 > sum2 and sum1 > sum3)
        {
            sum1 -= s1[top1];
            top1++;
        }
        else if (sum2 > sum1 and sum2 > sum3)
        {
            sum2 -= s2[top2];
            top2++;
        }
        else if (sum3 > sum2 and sum3 > sum1)
        {
            sum3 -= s3[top3];
            top3++;
        }
    }

    cout << "The sum which can be happen in all three stacks are : " << ans;

    return 0;
}