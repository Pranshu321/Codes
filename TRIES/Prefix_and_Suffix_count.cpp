#include <bits/stdc++.h>

using namespace std;

#define ll long long int

struct Node{
    Node*next[26];
    int cntendwith=0;
    int cntprefix=0;

    Node*getnode(char ch){
        return next[ch-'a'];
    }

    void put(char ch, Node*node){
        next[ch-'a']=node;
    }

    void increase_end(){
       cntendwith++;
    }
    void increase_prefix(){
       cntprefix++;
    }

    void reduce_end(){
        cntendwith--;
    }
    void reduce_prefix(){
        cntprefix--;
    }

    int getendwith(){
        return cntendwith;
    }

    int getprefix(){
        return cntprefix;
    }
};

class Trie{
private:
    Node*root;
    public:

    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string w){
        // Write your code here.
        Node*it=root;
      for(int i=0;i<w.size();i++){
          if(!it->next[w[i]-'a']){
              it->put(w[i],new Node());
          }
          it=it->getnode(w[i]);
          it->increase_prefix();
      }
      it->increase_end();
    }

    int countWordsEqualTo(string word){
        // Write your code here.
        Node*it=root;
       for(int i=0;i<word.size();i++){
           if(it->next[word[i]-'a']){
               it=it->getnode(word[i]);
           }
           else
           return 0;
       }
       return it->getendwith();
    }

    int countWordsStartingWith(string w){
        // Write your code here.
        Node*it=root;

      for(int i=0;i<w.size();i++){
          if(it->next[w[i]-'a']){
              it=it->getnode(w[i]);
          }

          else
          return 0;
      }
      return it->getprefix();
    }

    void erase(string w){
        // Write your code here.
        Node*it=root;

      for(int i=0;i<w.size();i++){
          if(it->next[w[i]-'a']){
              it=it->getnode(w[i]);
              it->reduce_prefix();
          }

          else
          return;
      }
      it->reduce_end();
    }
};
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Trie *T;
    string s[]= {"Pranshu", "app", "apple", "apes"};
    for (auto i : s)
        T->insert(i);
    string w = "app";
    int ans = T->countWordsStartingWith(w);
    cout<<ans;

    return 0;
}