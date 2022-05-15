#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 char searching(string a,int n,char temp){
     int start=0,end=n-1;
     char res='#';
     while(start<=end){
         int mid=start+(end-start)/2;
         if(a[mid]==temp){
             start=mid+1;
         }
         else if(a[mid]<temp){
             start=mid+1;
         }
         else{
             res=a[mid];
             end=mid-1;
         }
     }
     return res;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int n; cin>>n;
 string s;
 cin>>s;
char temp; cin>>temp;
 cout<<"The next alphabet element is : "<<searching(s,n,temp);
 
 
 
 
return 0 ;
 
 
 } 