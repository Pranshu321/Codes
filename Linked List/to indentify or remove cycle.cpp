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
void remvove_cycle(node*&head){
    node*slow=head;
    node*fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(fast->next!=slow->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
void insert_cycle(node*&head,int pos){
    node*temp=head;
    node*startnode;
    int count=1;
    while(temp->next!=NULL)
    {if(count==pos)
        startnode=temp;
        temp=temp->next;
        count++;
    }
    temp->next=startnode;
}
bool detect_cycle(node*&head){
    node*slow=head;
    node*fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        return true;
    }
    return false;
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
	insert_cycle(head,3);
	//display(head);
	cout<<detect_cycle(head);
	cout<<"\n";
	remvove_cycle(head);
	cout<<detect_cycle(head)<<"\n";
	display(head);
	return 0;
}
