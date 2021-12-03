#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 // defining node
 struct node{
     int data;
     node*next;

     node(int val){
         data=val;
         next=NULL;
     }
 };
// inserting the node 
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
// deleting node
 int del(node*&head){
     if(head==NULL)
     return 0;

    node*temp=head;
    int val=head->data;

    head=head->next;

    delete temp;
    return val;

 }
 // counting the no. of digits in max element of an array
 int digits(int n)
{
    int i = 1;
    if (n < 10)
        return 1;
 
    while (n > (int)pow(10, i))
        i++;
    return i;
}

 void radix_sort(int a[],int n){
  int maxx=-1;
  for(int i=0;i<n;i++){
      maxx=max(maxx,a[i]);
  }
  int d=digits(maxx);
  node** bins;

  bins= new node*[10];
  for(int i=0;i<10;i++){
      bins[i]=NULL;
  }
// 1st pass mai last digit ke basis par list mai entry karni hai.
// and number of passes depend on the no of digigts in maxx element.
  for(int i=0;i<d;i++){
      for(int j=0;j<n;j++){
          insert(bins[a[j]/(int)pow(10,i)%10],a[j]);
      }
          int x=0,y=0;

          while(x<10){
              while(bins[x]!=NULL){
                  a[y++]= del(bins[x]);
              }
              x++;
          }
      
  }
 
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int a[]={573, 25, 415, 12, 161, 6};
 int n=sizeof(a)/sizeof(a[0]);

 radix_sort(a,n);

 for(int i=0;i<n;i++){
     cout<<a[i]<<" ";
 }
 
 
 
 
return 0 ;
 
 
 } 