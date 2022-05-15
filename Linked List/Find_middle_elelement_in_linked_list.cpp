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

 void insertAtlast(node*&head,int val){
     node*t=new node(val);
     if(head==NULL){
         head=t;
         return;
     }
     node*temp=head;
     while(temp->next!=NULL){
         temp=temp->next;
     }
     temp->next=t;
 }

 node* middle(node*head){
     node*fast=head;
     node*slow=head;

     while(fast->next!=NULL && fast!=NULL){
         fast=fast->next->next;
         slow=slow->next;
     }
     return slow;
 }


 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 node*head=NULL;
 insertAtlast(head,10);
 insertAtlast(head,20);
 insertAtlast(head,30);
 insertAtlast(head,40);
 insertAtlast(head,50);
 node*ans=middle(head);
 cout<<ans->data;
 
 
 
 
return 0 ;
 
 
 } 