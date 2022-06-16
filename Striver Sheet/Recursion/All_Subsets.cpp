#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;

void sets(int idx,int a[],vector<int>&set,vector<vector<int>>&ans,int n){ 
    ans.push_back(set);
    for(int i = idx ; i<n;i++){
        
        if(i>idx && a[i]==a[i-1]){
            continue;
        }
        else{
            set.push_back(a[i]);
            sets(i+1,a,set,ans,n);
            set.pop_back();
        }
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> temp;
    vector<vector<int>>ans;
    sets(0, a,temp,ans,n);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }


    return 0;
}