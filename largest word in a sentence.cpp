#include <bits/stdc++.h>
using namespace std;

int main() {
	// largest word in  a sentence
	int n;
	cin>>n;
	cin.ignore();
	char a[n+1];
	cin.getline(a,n);
	cin.ignore();
	int i=0;
	int curlength=0,maxlength=0,st=0,end=0;
	while(1)
	{ if(a[i]==' '||a[i]=='\0')
	    { if(curlength>maxlength)
	        { maxlength=curlength;
	            end=st; //it is storing the value stating of largest characyer
	            // and maxlength denote lenth and last position
	        } curlength=0;
	        st=i+1;
	    }
	    else
	    curlength++;
	    if(a[i]=='\0')
	    { break;}
	    i++;
	}
	cout<<"max lenth character :- "<<maxlength<<"\n";
	for(int j=0;j<maxlength;j++)
	{ cout<<a[j+end];}
	
	return 0;
}
