#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 class WordDictionary {
    struct node {
        char c;
        int word_end;
        node *next[26];
    };
    node *getNode(char c)
    {
        node *newnode=new node;
        newnode->c = c;
        newnode->word_end = 0;
        for(int i=0;i<26;++i)
            newnode->next[i] = NULL;
        return newnode;
    }
    node *root = getNode('/');
    
    void Insert(string s)
    {
        int index;
        int i=0;
        node *t = root;
        while(s[i])
        {
            index = s[i]-'a';
            if(!t->next[index])
                t->next[index] = getNode(s[i]);
            t = t->next[index];
            ++i;
        }
        t->word_end +=1;
    }
    
    bool Search_in(string s,node *t,int pos,int n)
    {        
        if(s[pos]=='.')
        {
            bool res = false;
            node *tent = t;
            for(int i=0;i<26;++i)
            {
                if(pos==n-1 && t->next[i])
                {
                    tent=t->next[i];
                    res |= tent->word_end>0?true:false;
                }
                else if(t->next[i] && Search_in(s,t->next[i],pos+1,n))
                    return true;
            }
            return res;
        }
        else if(t->next[s[pos]-'a'])
        {
            if(pos==n-1)
            {
                t = t->next[s[pos]-'a'];
                return t->word_end>0?true:false;
            }
            return Search_in(s,t->next[s[pos]-'a'],pos+1,n);
        }
        return false;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return Search_in(word,root,0,word.size());
    }
};
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 WordDictionary W;
 string s[]={"abc","add","ben","b.","b.t","b..",".",".be","ab."};

 for(auto i:s){
     W.addWord(i);
 }

 if(W.search("b.t")){
     cout<<"YES\n";
 }
 else
 cout<<"NO\n";

 if(W.search("abc")){
     cout<<"YES\n";
 }
 else
 cout<<"NO\n";

 if(W.search("af.")){
     cout<<"YES\n";
 }
 else
 cout<<"NO\n";
 
 
 
 
return 0 ;
 
 
 } 