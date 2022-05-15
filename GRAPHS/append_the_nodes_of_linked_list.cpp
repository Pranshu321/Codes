#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data; node*next;
    node*prev;
    node(int val){
    data=val;
    next=NULL;
    
    }
};
//To insert At head
void insertAthead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    head=n;
    
}
int length(node*&head){
    node*temp=head;
    int l=0;
    while(temp!=NULL)
    { l++;
        temp=temp->next;
    }
return l;}
node*appendnode(node*&head,int k){
node*newhead;
node*newtail;
node*tail=head;
int l=length(head);
int count=1;
while(tail->next!=NULL){
    if(count==l-k)
    newtail=tail; // in this we get new tail by minus the the postion to total length that //passed
    if(count==l-k+1)
    newhead=tail;
    count++;
    tail=tail->next;
}
newtail->next=NULL;
tail->next=head;
 return newhead;
}
// to insert at last  linked list
void insertAtlast(node*&head,int val){
    if(head==NULL)
    { insertAthead(head,val);
        return;
    }
    node*n= new node(val);
    node*temp=head;
    while(temp->next!=NULL)
    { temp=temp->next;}
    temp->next=n;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL)
    { cout<<temp->data<<"-> ";
        temp=temp->next;
    } cout<<"NULL"<<"\n";
}
int main() {
	// doubly linked list insertion and deletion.
	node*head=NULL;
	insertAtlast(head,1);
	insertAtlast(head,2);
	insertAtlast(head,3);
	insertAtlast(head,4);
	insertAtlast(head,5);
	insertAtlast(head,6);
	display(head);
	node*head1=appendnode(head,3);
	display(head1);
	return 0;
}
