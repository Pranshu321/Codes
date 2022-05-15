#include <bits/stdc++.h>
using namespace std;
void primesieve(int n)
{ int p[100]={0};
    for(int i=2;i<=n;i++)
    { if(p[i]==0)
        { for(int j=i*i;j<=n;j+=i)
        {p[j]=1;}
            
        }
    }
for(int i=2;i<=n;i++)
    { if(p[i]==0)
        cout<<i<<" ";
    }
}
int main() {
	// seive of eramthoses of prime
	int n;
	cin>>n;
	primesieve(n);
	return 0;
}
