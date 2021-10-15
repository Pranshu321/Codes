#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
int first_occur(int a[],int n,int num){
    int start=0,end=n-1;
    int res=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==num){
            res=mid;
            end=mid-1;
        }
        else if(a[mid]<num){
            start=mid+1;
        }
        else
        end=mid-1;
    }
    return res;

}
int last_occur(int a[],int n,int num){
    int start=0,end=n-1;
    int res=0;
    while(start<=end){
        int mid=start+(end-start)/2;
        if(a[mid]==num){
            res=mid;
            start=mid+1;
        }
        else if(a[mid]<num){
            start=mid+1;
        }
        else
        end=mid-1;
    }
    return res;

}

 int count_element(int a[],int n,int num){
   int first=first_occur(a,n,num);
   int last=last_occur(a,n,num);
   return last-first+1;
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
 int temp; cin>>temp;
 cout<<"The count of the element is : "<<count_element(a,n,temp);
 
 
 
return 0 ;
 
 
 } 