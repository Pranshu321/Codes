#include <bits/stdc++.h>

using namespace std;

#define int long long
vector<vector<int>>ans;
void solve(int idx,vector<int>&a){
    if(idx==a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        swap(a[i] , a[idx]);
        solve(idx+1,a);
        swap(a[i] , a[idx]);
    }
}
int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    vector<int>a = {1,2,3};
    solve(0,a);
    // cout<<ans.size();
    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}