#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// SCRAMBLED STRING 
bool Scrambled_string(string a,string b){
    int n=a.length();
    if(n==0){
        return true;
    }
    if(a==b)
    return true;
    for(int i=1;i<n;i++){
    if(Scrambled_string(a.substr(0,i),b.substr(n-i,i)) && Scrambled_string(a.substr(i,n-i),b.substr(0,n-i))){
        return true;
    }
    if(Scrambled_string(a.substr(0,i),b.substr(0,i)) && Scrambled_string(a.substr(i,n-i),b.substr(i,n-i))){
        return true;
    }
    }
    return false;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string a="coder";
	string b="ocred";
	if(Scrambled_string(a,b)){
	    cout<<"Scrambled string";
	    
	}
	else
	cout<<"Not Scrambled string";
	
	return 0;
}