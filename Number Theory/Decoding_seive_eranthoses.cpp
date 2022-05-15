#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=2e6+10;
int hsh[N];
int canremove[N];
int hp[N];

vector<int> distinctPF(int x){  // Pushing Distinct elements in vector......
    vector<int>ans;
    while(x>1){
        int pf=hp[x];  //  Prime Factor of number which are distinct.
        while(x%pf==0)
        x/=pf;

        ans.push_back(pf);
    }
    return ans;
}
int main(){
cin.tie(0); cout.tie(0);
for(int i=2;i<N;i++){  // Marking the elements
    if(hp[i]==0){
        for(int j=i;j<N;j+=i){
            hp[j]=i;
        }
    }
}
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        hsh[x]=1;
    }
    for(int i=2;i<N;i++){
        if(hsh[i]){
            for(ll j=i;j<N;j*=i){
                canremove[j]=1;
            }
        }
    }
    while(q--){
        int x;
        cin>>x;
        vector<int> pf=distinctPF(x);
        bool flag=false;
        for(int i=0;i<pf.size();i++){
            for(int j=i;j<pf.size();j++){
                int product=pf[i]*pf[j];
            if(i==j && x%product!=0)
            continue;
         int toremove = x/product;
         if(canremove[toremove]==1 || toremove==1)
          {flag=true;
          break;
          }  
          }
          if(flag)
          break;
        }
        cout<< (flag ? "YES\n" : "NO\n");
    }


  return 0;
}