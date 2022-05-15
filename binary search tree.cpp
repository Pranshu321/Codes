#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
};
    node*getnewnode(int data)
{ node*newnode= new node();
    newnode ->data= data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}
node*insert(node*root, int data)
{ if(root==NULL)
    {root = getnewnode(data);
        return root;
    }
    else if( data<=root->data)
    { root->left= insert(root->left,data);
        
    }
    else
    { root->right= insert(root->right,data);
        
    }
return root;
    
}
bool search(node*root,int data)
{ if(root==NULL) return false;
    else if(root->data==data) return true;
    else if(data <= root->data) return search(root->left,data);
    else
    return search(root->right,data);
}
int main() {
	// your code goes here
node*root=NULL;
	root = insert(root,15);	
	root = insert(root,10);	
	root = insert(root,20);
	root = insert(root,25);
	root = insert(root,8);
	root = insert(root,12);
	// Ask user to enter a number.  
	int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(search(root,number) == true) cout<<"Found\n";
	else cout<<"Not Found\n";
	//return 0;
}
