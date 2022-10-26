#include<iostream>
using namespace std;


int min_jumps(int a[],int n){
    if(n<=1){
        return 0;
    }
    if(a[0]==0){
        return -1;
    }
    int maximum_ladder_reach = a[0] , stairs = a[0] , jumps=1;

    for(int i=1;i<n;i++){
        if(i==n-1){
            return jumps;
        }
        maximum_ladder_reach = max(maximum_ladder_reach , i + a[i]);

        stairs--;

        if(stairs==0){
            jumps++;
            if(maximum_ladder_reach<=i){
                return -1;
            }
            stairs = maximum_ladder_reach  - i; 
        }
    }
    return -1;
}

int main(){
    
    int n; cin>>n;
    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<min_jumps(a,n);


    return 0;
}