#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

void Shell_Sort(int a[],int n){
    

    for(int gap=n/2;gap>=1;gap/=2){ // For each gap 

        for(int i=gap;i<n;i++){ // gap traversal.

            int temp=a[i]; // Saving element
            int j=i-gap;

            while(j>=0 && a[j]>temp){ //swaping piche wale and aaage wale gap mai jo bhi hai sab ko check kar rahe hai.
                a[j+gap]=a[j];
                j=j-gap;
            }
        a[j+gap]=temp;
        }
    }
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 int a[]={11,13,7,12,16,9,24,5,10,3};
 int n= sizeof(a)/sizeof(a[0]);
 Shell_Sort(a,n);

 for(auto i: a){
     cout<<i<<" ";
 }

 
 
 
return 0 ;
 
 
 } 