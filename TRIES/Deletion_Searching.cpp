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
     node*next[26]; 
     bool end_of_word;
 };

 struct node *getNode()
{
	struct node *pNode = new node;

	pNode->end_of_word = false;

	for (int i = 0; i < 26; i++)
		pNode->next[i] = NULL;

	return pNode;
}

 void insert(node*root,string key){
     node*it=root;

     for(int i=0;i<key.length();i++){
         int idx=key[i]-'a';
         if(!it->next[idx]){
             it->next[idx]=getNode();
         }
         it=it->next[idx];
     }
     it->end_of_word=true;
 }
 
 void del(node*root,string s){
     node*it=root;
     int n=s.length();
     for(int i=0;i<n;i++){
      it->next[s[i]-'a']->end_of_word=false;
      it=it->next[s[i]-'a'];
     }
 }

 bool search(node*root,string key){
     node*it=root;

     for(int i=0;i<key.length();i++){
         if(!it->next[key[i]-'a']){
              return false;
         }
         it=it->next[key[i]-'a'];
     }
     return it->end_of_word;
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<string>v={"pranshu","jain","aca","point"};
 node*root=getNode();
 for(auto i:v){
     insert(root,i);
 }

 if(search(root,"point")){
     cout<<"TES";
 }
 else
 cout<<"no";
 del(root,"point");
 cout<<endl;
 if(search(root,"point")){
     cout<<"TES";
 }
 else
 cout<<"no";
 
 
 
 
return 0 ;
 
 
 } 
