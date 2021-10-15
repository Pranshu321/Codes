#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 bool isvalid(int a[],int n,int k,int mid){
     int sum=0,no_of_students=1;
     for(int i=0;i<n;i++){
         sum+=a[i];
         if(sum>mid){
             no_of_students++;
             sum=a[i];
         }
         if(no_of_students>k){
             return false;
         }
     }
     return true;
 }
 int minimum_pages(int a[],int n,int k){
     int start=0,end,res=-1;
     for(int i=0;i<n;i++){
         end+=a[i];
     }
     while(start<=end){
         int mid=start+(end-start)/2;
         if(isvalid(a,n,k,mid)){
             res=mid;
             end=mid-1;
         }
         else{
             start=mid+1;
         }
     }
     return res;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
 int k; cin>>k;
 int a[n];
 for(int i=0;i<n;i++){
     cin>>a[i];
 }
 cout<<"The minimum no. of page allocated is : "<<minimum_pages(a,n,k);
 
 
 
 
return 0 ;
 
 
 } 