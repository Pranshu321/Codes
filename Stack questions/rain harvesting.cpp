#include <bits/stdc++.h>
using namespace std;
void largestrectanglearea(vector<int>v){
    int i=0,ans=0,n=v.size();
    stack<int>st;
    v.push_back(0);
    while(i<n){
        while(!st.empty() && v[st.top()]<v[i]){ 
            int t=st.top();
            st.pop();
            if(st.empty()){ 
                
            break;
            }
            else
            { int len=i-st.top()-1; 
                ans+=(min(v[st.top()],v[i])-v[t])*len;
            }
        }
        st.push(i);
        i++;
    }
    cout<<ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n; cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++){
	int a; cin>>a;
	    v.push_back(a);
	}
	largestrectanglearea(v);
	return 0;
}
