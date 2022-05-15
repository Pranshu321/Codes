#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> &s , int temp){
    if(s.size()==0 || s.top()<temp ){ // for decending
    //if(s.size()==0 || s.top()>temp ){ // for ascending
            s.push(temp);
            return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}
void sorted(stack<int> &s){
    if(s.size() == 1)
    return;
    int temp = s.top();
    s.pop();
    sorted(s);
    insert(s,temp);
}
int main(){
    int arr[6]  = {5,6,9,1,7,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(arr[i]);
    }
   sorted(s);
   while(s.size()!=0){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}