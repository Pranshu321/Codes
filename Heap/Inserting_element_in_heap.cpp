#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void heapify(int a[],int n,int i){
    int parent=(i-1)/2;  //finding parent
    if(a[parent]>0){
        if(a[i]>a[parent]){
            swap(a[i],a[parent]);
            heapify(a,n,parent);
        }
    }
}
void insert(int a[],int &n,int key){
    n=n+1; // increasing size;
    a[n-1]=key; // setting the n-1 
    heapify(a,n,n-1); // making heap
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
 
    int n = 5;
 
    int key = 15;
 
    insert(arr, n, key);
 
    print(arr, n);
	
	return 0;
}