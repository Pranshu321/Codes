#include <bits/stdc++.h>

using namespace std;

#define int long long

void insert(stack<int>&s,int temp){
    if(s.size()==0){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
}


void Rev(stack<int>&s){
    if(s.size()==0){
        return;
    }
    int val = s.top();
    s.pop();
    Rev(s);
    insert(s,val);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(0);
    s.push(2);

    // while (!s.empty())
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }

    // cout<<"dffd"<<s.top();
    cout<<s.size();
    
    Rev(s);
    cout<<s.size();
    cout<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    return 0;
}