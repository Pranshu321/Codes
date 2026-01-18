#include <bits/stdc++.h>

using namespace std;

#define int long long

void insert(vector<int>&a,int temp){
    if(a.size()==0 or a[a.size()-1]<=temp){
        a.push_back(temp);
        return;
    }
    int val = a[a.size()-1];
    a.pop_back();
    insert(a,temp);
    a.push_back(val);
}

void Sort(vector<int>&a){
    if(a.size()==1){
        return;
    }
    int temp = a[a.size()-1];
    a.pop_back();
    Sort(a);
    insert(a,temp);
}

int32_t main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);

    vector<int>v = {7,5,1,9,0,4};

    Sort(v);

    for(auto i : v){
        cout<<i<<" ";
    }

    return 0;
}