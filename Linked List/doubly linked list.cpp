#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class node{
    public:
    int data;
    node*next; node*prev;
    node(int x){
        data=x;
        next=NULL;
        prev=NULL;
    }
};
void insertAthead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    if(head!=NULL)
    head->prev=n;
    head=n;
}
void insertAtTail(node*&head,int val){
    if(head==NULL){
        insertAthead(head,val);
        return;
    }
    node*n=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
    
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<"\n";
}
void deleteAthead(node*&head){
    node*todelete=head;
    head=head->next;
    head->prev=NULL;
    delete(todelete);
}
void deletion(node*&head,int pos){
    if(pos==1){
        deleteAthead(head);
        return;
    }
    node*temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL)
    temp->next->prev=temp->prev;
    delete(temp);
    
}
void deletionAthead(node*&head){
    head=head->next;
    
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	node*head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	insertAtTail(head,4);
	display(head);
	insertAthead(head,0);
	display(head);
	//deletion(head,5);
	deletion(head,1);
	display(head);
	return 0;
}
