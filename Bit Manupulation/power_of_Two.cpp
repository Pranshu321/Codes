#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

bool power_of_two(int n)
{
   return n && (!(n & (n - 1)));
}
int main()

{
   ios_base::sync_with_stdio(false);
   cout.tie(0);
   cin.tie(0);

   if (power_of_two(2))
   {
      cout << "Yes , It is Power of 2";
   }
   else
   {
      cout << "No , It is Power of 2";
   }

   return 0;
}