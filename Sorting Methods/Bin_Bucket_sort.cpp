#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 const int N=1e5+10;
 vector<int> v[N];
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;

 void bucketSort(float a[], int n)
{
    vector<float> v[n];
    
    for (int i=0; i<n; i++)
    {
       int x = n*a[i];
       v[x].push_back(a[i]);
    }
    for (int i=0; i<n; i++)
       sort(v[i].begin(), v[i].end());
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < v[i].size(); j++)
          a[idx++] = v[i][j];
}
int main()
{
    float a[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(a)/sizeof(a[0]);
    
    
    bucketSort(a, n);
    
    cout << "Sorting Processes \n";
    for (int i=0; i<n; i++)
       cout << a[i] << " ";
 
 
return 0 ;
 
 
 } 

/*
The bin bucket sorting is efficient in the of [0,1] means mainly it works good in float numbers .
In this the list is maintained , as in the graph adajency list in graph.


*/