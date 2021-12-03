#include <bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r)
{ int n1= mid-l+1;
    int n2= r-mid;
    int x[n1],y[n2]; //temparory array
    for(int i=0;i<n1;i++)
    { x[i]=a[l+i]; }
    for(int i=0;i<n2;i++)
    { y[i]=a[mid+1+i]; }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    { if(x[i]<y[j])
        { a[k]=x[i];
            i++; k++;
        }
        else
        {a[k]=y[j];
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
}
void mergesort(int a[],int l,int r)
{ if(l<r)
{int mid=(l+r)/2;
    mergesort(a,l,mid); // first half from starting to mid
    mergesort(a,mid+1,r); // second half from mid+1 to end.
    merge(a,l,mid,r);}
}
int32_t main() {
	// i this also we have to give the end pointer to the n-1.
	ios::sync_with_stdio(0);
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	mergesort(a,0,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	return 0;
}
