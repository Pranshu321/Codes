#include <bits/stdc++.h>
using namespace std;

int main() {
	// max number of character that repeated by string 
	int idx[26],maxi=0; char ans='a';
	string s;
	cin>>s;
	for(int i=0;i<26;i++)
	{ idx[i]=0;
	    }
	    for(int i=0;i<s.size();i++)
	    { idx[s[i]-'a']++;
	        
	    }
	    for(int i=0;i<26;i++)
	    { if(idx[i]>maxi)
	        { maxi=idx[i];
	            ans=i+'a';
	        }
	    }
	    cout<<maxi<<" "<<ans;
	return 0;
}
