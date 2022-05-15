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
    cout << 7 / 2 << "\n"; // The output will be in highest datatype.

    cout << 7 / 2.0; // here highest value datatype will be float.

    // Priority Order Of Datatype
    /* 
       1. Double
       2. Float
       3. Long long int
       4. long int
       5. int
       6. characters
    */
    
    // Ranges of datatype 
    /* int , char , long int , long long int , float , double. 
       -10^9 < int < 10^9
       -10^12 < long int < 10^12
       -10^18 < long long int < 10^18
    */
    
    /*
    Float and double can store big numbes like 10^24 but at the cost of accuracy.That's why we dont use it in calculations.
    */

    return 0;
}