#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void ComputeNumDivBythree(vector<int>a,int k){
    pair<int,int>ans;
    int sum=0;
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    bool found=false;
    if(sum%3==0){ // it is fact that the number divisible by 3 only if the sum of indivisual number sum id divisible by 3;
        found=true;
        ans=make_pair(0,k-1);
    }
    for(int i=k;i<a.size();i++){
        if(found){
            break;
        }
        sum=sum-a[i-k];
        sum=sum+a[i];
        if(sum%3==0){
            found=true;
            ans=make_pair(i-k+1,i);
        }
    }
    if(!found){
        ans=make_pair(-1,0);
    }
    if(ans.first==-1){
        cout<<"No number exist";
    }
    else{
        for(int i=ans.first;i<=ans.second;i++){
            cout<<a[i]<<" ";
        }
}
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	vector<int>a={84,23,45,12,56,82};
	int k=3;
	ComputeNumDivBythree(a,k);
	
	
	return 0;
}