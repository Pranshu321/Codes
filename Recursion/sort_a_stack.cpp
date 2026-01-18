#include<bits/stdc++.h>
 
 using namespace std;
 
 #define int long long
 
 void insert(stack<int>&s,int t){
    if(s.size()==0 or s.top()<=t){
        s.push(t);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,t);
    s.push(val);
 }

 void Sort(stack<int>&s){
    if(s.size()==1){
        return;
    }
    int t = s.top();
    s.pop();
    Sort(s);
    insert(s,t);
 }

 int32_t main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 stack<int>s;
 s.push(1);
 s.push(3);
 s.push(0);
 s.push(2);

 Sort(s);

 while(!s.empty()){
    cout<<s.top()<<" ";
    s.pop();
 }
 
 
 
 
return 0 ;
 
 
 } 