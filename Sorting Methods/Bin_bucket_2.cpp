#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>;
 struct node{
     int data;
     node*next;

     node(int val){
         data=val;
         next=NULL;
     }
 };

 void insert(node*&head,int n){
     if(head==NULL){
         head=new node(n);
         return;
     }

     node*t= head;
     while(t->next!=NULL){
         t=t->next;
     }

     t->next= new node(n);
 }

 int del(node*&head){
     if(head==NULL)
     return 0;

    node*temp=head;
    int val=head->data;

    head=head->next;

    delete temp;
    return val;

 }

 void bin_bucket(int a[],int n,int maxx){
  node** bucket;
  bucket= new node*[maxx];

  for(int i=0;i<maxx;i++){
      bucket[i]=NULL;
  }
  
  for(int i=0;i<n;i++){
      insert(bucket[a[i]],a[i]);
  }

  int x=0,y=0;
  while(x<maxx+1){
      while(bucket[x]!=NULL){
          a[y++]=del(bucket[x]);
      }
      x++;
  }

 }

 void print(int a[],int n){
     for(int i=0;i<n;i++){
         cout<<a[i]<<" ";
     }
 }

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a[]={6,8,3,10,15,6,9,12,6,3};
 int n=sizeof(a)/sizeof(a[0]);
 int mazz=-1;
 for(int i=0;i<n;i++){
     mazz=max(mazz,a[i]);
 }

 bin_bucket(a,n,mazz);
 print(a,n);

 
 
 
 
return 0 ;
 
 
 } 