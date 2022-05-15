#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
int t; cin>>t;
while(t--){
    int n; cin>>n;
    vector<pair<int,int>>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    int l,p;
    cin>>l>>p; // the truck distance from city and p present fuel
    for(int i=0;i<n;i++){
        a[i].first=l-a[i].first;
    }
    sort(a.begin(),a.end());
    int ans=0;
    int curr=p; // setting curr with present fuel
    bool flag=0;
    priority_queue<int,vector<int>>pq;
    for(int i=0;i<n;i++){
        if(curr>=l){  // if current greater than distance from city
            break;  
        }
        while(curr<a[i].first){
            if(pq.empty()){ // if it is empty break;
                flag=1;
                break;
            }
            ans++;  //else add fuel to truck;
            curr+=pq.top();
            pq.pop();
        }
        if(flag)
        break;
        pq.push(a[i].second);
    }
    if(flag){
        cout<<"-1"<<"\n";
        continue;
    }
    while(!pq.empty() && curr<l){ // if it is still have to reach city;
        curr+=pq.top();
        pq.pop();
        ans++;
    }
    if(curr<l){
        cout<<"-1"<<"\n";
        continue;
    }
    cout<<ans<<"\n";
    
}
	
	return 0;
}
// 1
// 4
// 4 4
// 5 2
// 11 5
// 15 10
// 25 10
// output 2