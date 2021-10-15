#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 int binary_asc(int a[],int start,int end,int num){
             while(start<=end){
         int mid=start+(end-start)/2;
         if(a[mid]==num)
         return mid+1;
         else if(a[mid]<num)
         {  start=mid+1; }
         else
         end=mid-1;
     }
     return -1;
 }
 int binary_dsc(int a[],int start,int end,int num){
             while(start<=end){
         int mid=start+(end-start)/2;
         if(a[mid]==num)
         return mid+1;
         else if(a[mid]<num)
         {  end=mid-1; }
         else
         start=mid+1;
     }
     return -1;
 }
 int peak_element(int a[],int n){
     int start=0,end=n-1;
     while(start<=end){
         int mid=start+(end-start)/2;
         if(mid>0 || mid<n-1){
             if(a[mid]>a[mid+1] && a[mid]>a[mid-1]){
                 return mid;
             }
             else if(a[mid]<a[mid+1]){
                 start=mid+1;
             }
             else end=mid-1;
         }
         else if(mid==0){
             if(a[mid]>a[mid+1])
             return 0;
             else return 1;
         }
         else{
             if(a[mid]>a[n-2]){
                 return mid;
             }
             else
             return n-2;
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
 int temp;
 cin>>temp;
 int pos=peak_element(a,n);
 if(binary_asc(a,0,pos-1,temp)!=-1){
     cout<<"FINDED";
 } 
 else if(binary_dsc(a,pos,n-1,temp)!=-1){
     cout<<"FINDED";
 }
 else{
     cout<<"NOT FINDED";
 }
 
 
 
return 0 ;
 
 
 } 