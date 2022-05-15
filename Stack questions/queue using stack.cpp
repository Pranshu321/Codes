#include <bits/stdc++.h>
using namespace std;
class que{
    stack<int>s1;
    stack<int>s2;
    public:
    void Push(int x){
        s1.push(x);
    }
    void Pop()
    { if(s1.empty() && s2.empty())
        {cout<<"queue empty";
    return;}
        if(!s2.empty()){
s2.pop();}
        else{
while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }}
  s2.pop();
    }
    bool Empty(){
        if(!s1.empty() && s2.empty())
        return true;
        else
        return false;
    }
    void display(){
        if(!s2.empty()){
cout<<s2.top()<<" "; }
else{
        while(!s1.empty()){
            s2.push(s1.top());
s1.pop();
        
    }
cout<<s2.top()<<" ";
    }
}
};
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	que q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
//	q.display();
	cout<<"\n"; q.Pop();
	return 0;
}
