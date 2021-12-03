#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isperfect(int n){
  int sum=1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0){
            if(i==n/i){
                sum+=i;
            }
            else{
                sum+=i+n/i;
            }
        }
    }
    if(sum==n && n!=1){
        return true;
    }
    return false;
}
int SumMax(int a[],int n,int k){
    if(n<k){
        cout<<"dont exist";
        return -1;
    }
    int res=0;
    for(int i=0;i<k;i++){
        res+=a[i];
    }
    int sum=res;
    for(int i=k;i<n;i++){
        sum+=a[i]-a[i-k];
        res=max(sum,res);
    }
    return res;
}
int PerfectNumber(int a[],int n,int k){
    for(int i=0;i<n;i++){
        if(isperfect(a[i])){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    return SumMax(a,n,k);
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={28,2,3,6,496,99,8128,24};
	int k=4,n=8;
	cout<<PerfectNumber(a,n,k);
	
	return 0;
}