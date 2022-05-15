#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 
 

 struct TrieNode{
     struct TrieNode*next[2];
     TrieNode(void){
         next[0]=NULL;
         next[1]=NULL;
     }

 };

TrieNode*buildtree(vector<int> &a){
    TrieNode*root=new TrieNode;
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        TrieNode*cur=new TrieNode;
        for(int i=31;i>=0;i--){
            int bit= (num>>i)&1;
            if(!cur->next[bit])
            cur->next[bit]=new TrieNode;
            cur=cur->next[bit];
        }
    }
    return root;
}

int helper(TrieNode*root,vector<int>&a){
    int res=0;
for(int i=0;i<a.size();i++){
    int num=a[i];
    TrieNode*it=root;
    int cur_max=0;
    for(int i=31;i>=0;i--){
        int bit= ((num>>1)&1)?0:1;
        if(it->next[bit]!=NULL){
            cur_max <<=1;
            cur_max |=1;
            it=it->next[bit];
        }
        else{
            cur_max <<=1;
            cur_max |=0;
            it=it->next[bit];
        }
    }
    res=max(res,cur_max);
}
return res;
}
 
 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<int> a={3,10,5,15,2};
 TrieNode*root=buildtree(a);
 int ans=helper(root,a);
 cout<<ans;
 
 
return 0 ;
 
 
} 