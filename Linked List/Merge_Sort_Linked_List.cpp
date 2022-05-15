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
    node* Merge_Both(node*first , node * second){ // This is Function where we merge the two linked list.
      node*ans=NULL;
      
      if(!first)
      return second;
      
      if(!second)
      return first;
      
      if(first->data <= second->data){
          ans=first;
          ans->next= Merge_Both(first->next,second);
      }
      else{
          ans=second;
           ans->next= Merge_Both(first,second->next);
      }
      return ans;
  }
  
  void Find_Middle(node*cur,node**first,node**second){ // this is the function in which we finding the middle element 
      node*fast;
      node*slow;
      slow=cur;
      fast=cur->next;
      
      while(fast!=NULL){
          fast=fast->next;
          if(fast!=NULL){
              slow=slow->next;
              fast=fast->next;
          }
      }
      
      *first=cur;
      *second=slow->next;
      slow->next=NULL;
  }

  void mergesorting(node **head){ // main function performing merge sort.
      node*cur=*head;
      node*first;
      node*second;
      
      if(!cur or !cur->next)
      return;
      
      Find_Middle(cur,&first,&second);
      
      mergesorting(&first);
      mergesorting(&second);
      *head= Merge_Both(first,second);
      
  }
  
    
    node* mergeSort(node* head) {
        mergesorting(&head);
        return head;
    }

    void insertAtLast(node*&head,int val){
        node*t=new node(val);
        if(!head){
            head=t;
            return;
        }

        node*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=t;
    }

    void display(node*head){
        node*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" - >";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
  node*head=NULL;
  insertAtLast(head,20);
  insertAtLast(head,60);
  insertAtLast(head,10);
  insertAtLast(head,0);
  insertAtLast(head,40);
  display(head);
 node*ans= mergeSort(head);
  display(ans);
 
 
 
 
return 0 ;
 
 
 } 