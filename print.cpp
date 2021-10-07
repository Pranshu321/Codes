#include<iostream>
using namespace std;
int addnum(int n){
   if(n==0)
   return 0;
   return n+addnum(n-1);
}
int main(){
    int n; cin>>n;
      cout<<addnum(n);
    return 0;
}