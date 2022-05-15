#include <bits/stdc++.h>
using namespace std;
int postfixevalution(string s){
    stack<int>st;
    for(int i=0;i<s.length();i++){
        if(s[i]>='0' && s[i]<='9')
        st.push(s[i]-'0');
        else
        { int op2=st.top(); // The top element always we second oprand.
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i]){
                case'+': st.push(op1+op2);
                break;
                case'-': st.push(op1-op2);
                break;
                case'*': st.push(op1*op2);
                break;
                case'/': st.push(op1/op2);
                break;
                case'^': st.push(pow(op1,op2));
                break;
            }
        }
    }
return st.top();}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s; cin>>s;
	cout<<postfixevalution(s);
	return 0;
}
