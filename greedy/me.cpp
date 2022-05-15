#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n, m;
    cin >> n >> m;

    int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<int> ans;
for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
 
                // Counting all neighbouring 1s
 
                if (i > 0){

                }
                    
                if (j > 0){

                }
                    
                if (i > 0 && j > 0){
                    
                }
                    
                if (i < n - 1){

                }
                    
                if (j < n - 1){

                }
                    
                if (i < n - 1 && j < n - 1){

                }
                    
                if (i < n - 1 && j > 0){

                }
                    
                if (i > 0 && j < n - 1){

                }
            }
}
                    
 
 
 
 
return 0 ;
 
 
 } 