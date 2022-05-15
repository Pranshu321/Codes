#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool ispallindrome(int n){
    int temp=n,num=0;
    while(temp!=0){
        num=num*10+temp%10;
        temp=temp/10;
    }
    if(num==n){
        return true;
    }
    return false;
}
int find_Pallindromic_SubArray(vector<int>a,int k){
    int num=0;
    for(int i=0;i<k;i++){
        num=num*10+a[i];
    }
    if(ispallindrome(num)){
        return 0;
    }
    for(int i=k;i<a.size();i++){
        num=(num%(int)pow(10,k-1))*10+a[i]; // special form to minus and plus
        if(ispallindrome(num)){
            return i-k+1;
        }
    }
    return -1;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	vector<int>a={2,3,5,1,1,5};
	int k=4;
	int ans=find_Pallindromic_SubArray(a,k);
	if(ans==-1){
	    cout<<"does not exist";
	}
	else{
	for(int i=ans;i<ans+k;i++){
	    cout<<a[i]<<" ";
	}
	}
	return 0;
}