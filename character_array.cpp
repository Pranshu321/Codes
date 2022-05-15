#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n; cin>>n;
	char a[n+1]; // because there is last character '/0' also which denote end of sentence.
	cin>>a;
	int check=0;
for(int i=0;i<n;i++)
{ if(a[i]!=a[n-1-i])
  { check=1;
      break;
  }
    }
    if(check==0)
    cout<<"\n its a pallindrome";
    else
    cout<<"\n its not a pallindrome";
	return 0;
}
