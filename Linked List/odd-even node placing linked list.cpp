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
void oddevennode(node*&head){
    node*odd=head;
    node*even=head->next;
    node*evenstart=even;
    while(odd->next!=NULL && even->next!=NULL)
    { odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next!=NULL)
    even->next=NULL;
    
}
void insertAthead(node*&head,int val){
    node*n=new node(val);
     n->next=head;
    head=n;
}
void insertAtlast(node*&head,int val){
    node*n=new node(val);
    if(head==NULL)
    { head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
cout<<"NULL"<<"\n";}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	node*head1=NULL;
	insertAthead(head1,1);
	insertAtlast(head1,2);
	insertAtlast(head1,3);
	insertAtlast(head1,4);
	insertAtlast(head1,5);
	insertAtlast(head1,6);
	display(head1);
	oddevennode(head1);
		display(head1);
	return 0;
}
