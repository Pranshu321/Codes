#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 void bonacciseries(long n, int m)
{
    
    int a[m] = { 0 };
    a[n - 1] = 1;
    for (int i = n; i < m; i++)
        for (int j = i - n; j < i; j++)
            a[i] += a[j];
  
    for (int i = 0; i < m; i++)
        cout << a[i] << "  ";
}
  

int main()
{
    int N = 5, M = 15;
    bonacciseries(N, M);
    return 0;
}