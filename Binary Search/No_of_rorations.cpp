#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 int rotations(int a[],int n){
     int start=0,end=n-1;
     
     while(start<=end){
         int mid=start+(end-start)/2;
     int next=(mid+1)%n;  // setting the next index wrt mid element we are taking modulo n to make sure that bound will not exceed when it is at last element .
     int prev=(mid+n-1)%n; // setting the prev index wrt mid element we are taking modulo n to make sure that bound will not exceed when it is at starting element .
         if(a[mid]<=a[next] && a[mid]<=a[prev]){  // finding the minimum element which are smaller than both neighbours.
            return mid;
         }
         else if(a[start]<=a[mid]) // if starting element is smaller than mid element means that side array is sorted and we have to move other side because minimum element will be present in unsorted array .
         start=mid+1;
         else
         end=mid-1;
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
 cout<<"The no. of rotations are : "<<rotations(a,n);
 
 
 
 
return 0 ;
 
 
 } 