#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isfeasible(int a[],int n,int m,int min){
    int StudentAllocated=1,sum=0; // student allocation is 1 beacuse we are allocating to forst student;
    for(int i=0;i<n;i++){
        if(a[i]>min){  // if any element greater than min value is a fasle condition;
            return false;
        }
        if(sum+a[i]>min){
            StudentAllocated++;   // in any point the sum+next ele is greater than the min value means we need to allocate to next student;
            sum=a[i];  // ele added to mext stu so for that sum alos updated;
        }
        if(StudentAllocated>m)  // more student got allocated
        return false;
        else{
            sum+=a[i];  // adding pages for any student
        }
    }
    return true;
}
int minimumAllocatePages(int a[],int n,int m){
    if(n<m){
        return -1;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];  // max pages can be allocated to one stuent only;
    }
    int start=0,end=sum,ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;  // mid value of max pages
        if(isfeasible(a,n,m,mid)){  //if feasible we search for left side of list;
            ans=min(ans,mid);  // update answer
            end=mid-1;
        }
        else{
            start=mid+1;  // else sreach in right side
        }
    }
    return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int a[]={12,34,67,90};
	int n=4,m=2;
	cout<<minimumAllocatePages(a,n,m);
	
	return 0;
}