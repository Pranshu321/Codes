#include <bits/stdc++.h>
using namespace std;
class node{
  public:
  int data; node*next;
  node(int val){
      data=val;
      next=NULL;
  }  
  
};
node*reverse_node(node*&head,int k){
    node*pre=NULL;
    int count=0;
    node*curr=head;
    node*nxt;
    while(curr!=NULL && count<k)
{nxt=curr->next;
    curr->next=pre;
    pre=curr;
    curr=nxt;
    count++;
}
 if(nxt!=NULL)
 head->next=reverse_node(nxt,k);
 
 return pre;
}
void insert(node*&head,int val){
    node*n=new node(val);
    if(head==NULL)
    {head=n;
        return;
    }
    node*tem=head;
    while(tem->next!=NULL)
    { tem=tem->next;}
    tem->next=n;
    
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL)
    { cout<<temp->data<<"-> ";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	node*head=NULL;
	insert(head,1);
	insert(head,2);
	insert(head,3);
	insert(head,4);
	display(head);
	node*head1=reverse_node(head,2);
	display(head1);
	return 0;
}
