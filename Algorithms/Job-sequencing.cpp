#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 struct job
 {
     char id;
     int dead;
     int profit;
 };
 bool compare(job a,job b){
     return (a.profit>b.profit);
 }

 void Job_sehuedling(job a[],int n){
     sort(a,a+n,compare);
     int result[n];
     vector<bool>slot(n,false);

     for(int i=0;i<n;i++){
         for(int j=a[i].dead-1;j>=0;j--){    // As it is one based indexing for 0 based -1 is done.
             if(!slot[j]){
                 result[j]=i;
                 slot[j]=true;
                 break;
             }
         }
     }
     for(int i=0;i<n;i++){
         if(slot[i])
         cout<<a[result[i]].id<<" ";
     }
 }
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Following is maximum profit sequence of jobs \n";
    
   Job_sehuedling(arr,n);
 
 
return 0 ;
 
 
 } 