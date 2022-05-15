#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void hepify(int a[],int n,int i){
    int largest=i;
    int l=2*i+1; // left child finding formula
    int r=2*i+2;  // right child finding formula
    if(l<n && a[l]>a[largest]){
        largest=l;
    }
    if(r<n && a[r]>a[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(a[largest],a[i]);
    
    hepify(a,n,largest);
}
    
}
void deleteRoot(int a[],int &n){
    int last_ele=a[n-1];
    a[0]=last_ele;
    n=n-1;
hepify(a,n,0);
    
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int arr[] = { 10, 5, 3, 2, 4 };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
//    deleteRoot(arr, n);
//    deleteRoot(arr, n);
    print(arr,n); cout<<endl;
    hepify(arr,n,0);
    print(arr, n);
	
	return 0;
}