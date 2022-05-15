#include <bits/stdc++.h>
using namespace std;
void answer(int a[], int k, int n)
{ vector<int> ans ;
    deque<int> q ;
    for(int i=0;i<k;i++)
    { while(!q.empty() && a[q.back()]<a[i])
        { q.pop_back();}
        q.push_back(i);}
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++)
    { if(q.front()==i-k)
        q.pop_front();
        while(!q.empty() && a[q.back()]<a[i])
        { q.pop_back();}
        q.push_back(i);
        ans.push_back(a[q.front()]);}
    for(auto i: ans)
    cout<<i<<" ";
}
int main() {
	// your code goes here
	int a[10];
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{ cin>>a[i];}
	answer(a,k,n);
	return 0;
}
