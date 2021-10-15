#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 void search(int a[4][4],int n,int num){
     int i=0,j=n-1;
     while(i<n && j>=0){
         if(a[i][j]==num){
             cout<<"THE pos is present at : "<<i+1<<" "<<j+1;
             return;
         }
         else if(a[i][j]>num)
         j--;
         else
         i++;
     }
     cout<<"Not found";
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 int mat[4][4] = { { 10, 20, 30, 40 },
                      { 15, 25, 35, 45 },
                      { 27, 29, 37, 48 },
                      { 32, 33, 39, 50 } };
    search(mat, 4, 56);
 
 
 
 
return 0 ;
 
 
 } 