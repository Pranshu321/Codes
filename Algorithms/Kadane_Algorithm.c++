#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 // this is to find the maxmum sum sub_array
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n;
 cin>>n;
 int a[n];
 for(int i=0;i<n;i++)
 cin>>a[i];
 int curr=0,max_till_now=0;
 for(int i=0;i<n;i++){
  curr+=a[i];
  max_till_now=max(max_till_now,curr);
  if(curr<0)  // this is the main step of kadane algorithm
  curr=0;
 }
 cout<<max_till_now;
 
 
 
 
return 0 ;
 
 
 } 
 //https://meet.google.com/ymn-esya-okn