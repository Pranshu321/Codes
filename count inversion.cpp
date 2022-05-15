#include <bits/stdc++.h>
using namespace std;
long long merge(int a[],int l,int mid,int r)
{ int n1= mid-l+1;
   long long inv=0;
    int n2= r-mid;
    int x[n1],y[n2]; //temparory array
    for(int i=0;i<n1;i++)
    { x[i]=a[l+i]; }
    for(int i=0;i<n2;i++)
    { y[i]=a[mid+1+i]; }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    { if(x[i]<=y[j])
        { a[k]=x[i];
            i++; k++;
        }
        else
        {a[k]=y[j];
        inv+=n1-i; // this is because one half is already sorted so if first //element is big then all after also big than other side array
        k++; j++;}
    }
    while(i<n1)
    { a[k]=x[i];
        k++; i++;
    }
    while(j<n2)
    { a[k]=y[j];
        k++; j++;
    }
    return inv;
}
long long mergesort(int a[],int l,int r)
{ int inv=0;
    if(l<r)
{int mid=(l+r)/2;
   inv+= mergesort(a,l,mid); 
   inv+= mergesort(a,mid+1,r); 
    inv+=merge(a,l,mid,r);}
return inv;
    
}
int32_t main() {
	// inversion count problem.
	ios::sync_with_stdio(0);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	cout<<mergesort(a,0,n-1);
	
	return 0;
}

