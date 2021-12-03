#include <iostream>
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
void intersect(node*&head1,node*head2,int pos){
    node*temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    node*temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
    
}
int length(node*&head){
    node*temp=head;
    int len=0;
    while(temp!=NULL)
    { len++;
        temp=temp->next;
    }
    return len;
}
int findIntersect(node*head1,node*head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node*ptr1;
    node*ptr2;
    if(l1>l2){
        ptr1=head1;
        ptr2=head2;
        d=l1-l2;
    }
    else
    { ptr1=head2;
        ptr2=head1;
        d=l2-l1;
    }
    while(d){ptr1=ptr1->next;
        if(ptr1==NULL)
        return -1;
        d--;
    }
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1==ptr2)
        return ptr1->data;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
    
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
	node*head1=NULL;
	node*head2=NULL;
	insertAtlast(head1,1);
	insertAtlast(head1,2);
	insertAtlast(head1,3);
	insertAtlast(head1,4);
	insertAtlast(head1,5);
	insertAtlast(head1,6);
	insertAtlast(head2,9);
	insertAtlast(head2,10);
	intersect(head1,head2,3);
	display(head1);
	display(head2);
cout<<findIntersect(head1,head2);
	return 0;
}
