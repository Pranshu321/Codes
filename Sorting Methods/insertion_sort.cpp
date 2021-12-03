#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 

void insertion_sort(int a[],int n){
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
 
        /* Move elements of a[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
	}
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a[]={34,5,6,1,89,10};
 int n=6;
 insertion_sort(a,n);
 for(int i=0;i<n;i++){
	 cout<<a[i]<<" ";
 }
 
 
 
 
return 0 ;
 
 
 } 