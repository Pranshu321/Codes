#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data; node*next;
    node(int val)
    { data=val;
        next=NULL;
    }
};
void insertAthead(node*&head,int val)
{ node*ptr=new node(val);
    ptr->next=head;
    head=ptr;
}
void insertAtlast( node*&head,int val)
{    node*ptr= new node(val);
 if(head==NULL)
  { head=ptr;
      return;
  }
    node*temp=head;
    while(temp->next!=NULL)
    { temp=temp->next;
        
    }
    temp->next=ptr;
}
void display(node*head){
    node*temp=head;
    while(temp!=NULL)
    { cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"\n";
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	node*head=NULL;
	insertAtlast(head,1);
	insertAtlast(head,2);
	insertAtlast(head,3);
	insertAtlast(head,4);
	display(head);
	insertAthead(head,0);
	display(head);
	
	return 0;
}
