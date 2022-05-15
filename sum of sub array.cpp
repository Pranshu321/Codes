#include <bits/stdc++.h>
using namespace std;

int main() {
	// the sum of sub array equal to the sum given
	int n,s;
	cin>>n>>s;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	int i=0,j=0,st=-1,end=-1,sum=0;
	while(j<n && sum+a[j]<=s) /* we inilialize the st and end with -1 which shows
	that both are at before starting first we find the simple subarray is by adding 
	each a[j] elemets in sum and last check if its equal to a[j] oe not */
	{ sum+=a[j];
	    j++;
	}
	if(sum==s)
	{cout<<i+1<<" "<<j<<"\n";
	return 0;}
	while(j<n) /* in this we have find the j th position whehre sum is exceeding the 
the given sum so we now move start varaible till sum ==s if not check for all other varaible..*/	
	{ sum+=a[j];
	    while(sum>s)  
	    { sum-=a[i];
	        i++;
	    }
	if(sum==s)
	{ st=i+1;
	    end=j+1;
	break;}j++; }
	
	cout<<st<<" "<<end<<"\n";
	
	return 0;
}
