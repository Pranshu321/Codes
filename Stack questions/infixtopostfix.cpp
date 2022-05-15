#include <bits/stdc++.h>
using namespace std;
int prec(char c){
    if(c=='^')
    return 3;
    else if(c=='*' || c=='/')
    return 2;
    else if(c=='+' || c=='-')
    return 1;
    else
    return -1;
}
string infixtoprefix(string s){
    reverse(s.begin(),s.end());
    stack<char> st ;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z')
        res+=s[i];
        else if(s[i]==')') // here we make opening to closing bracket;
        st.push(s[i]);
        else if(s[i]=='(') //here closing bracket to opening bracket;
        { 
            while(!st.empty() && s[i]!=')'){
                res+=st.top();
                st.pop();}
           }
        else{
            while(!st.empty() && prec(st.top())>=prec(s[i]))
            { res+=st.top();
                st.pop();
            }
        st.push(s[i]);}
        
    }
    while(!st.empty())
    {
        res+=st.top();
    st.pop();
    }
reverse(res.begin(),res.end());
return res;
    
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	cout<<infixtoprefix("(a-b/c)*(a/k-l)");
	return 0;
}
