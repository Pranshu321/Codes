#include<bits/stdc++.h>
 
 using namespace std;
 #define ll long long int
 int peak_ele(int a[],int n){
     int start=0,end=n-1;
     while(start<=end){   // skipping the edge we will handel it later
         int mid=start+(end-start)/2;
         if(mid>0 || mid<n-1){    // checking that mid is peak element or not by checking it is greater than its both neighbour .
             if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
                 return a[mid];
             }
             else if(a[mid]<a[mid+1]){  // the one bigger than the mid we shift towards that side
                 start=mid+1;
             }
             else
             end=mid-1; 
         }
         else if(mid==0){     // handeling the edge conditionss of mid equal to 0
             if(a[mid]>a[mid+1])
             return a[mid];
             else
             return a[1];
         }
         else {    // handeling the mid==n-1
             if(a[mid]>a[n-2]){
                 return a[mid];
             }
             else
             return a[n-2];
         }
     }
     return -1;

 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 int n; cin>>n;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 cout<<"The peak element is : "<<peak_ele(a,n);
 
 
 
return 0 ;
 
 
 } 