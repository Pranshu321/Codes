#include <bits/stdc++.h>
using namespace std;
int reverse(int a)
{ int rev=0;
    while(a>0)
    { int b=a%10;
        rev=rev*10+b;
        a=a/10;
    }
    return rev;
}
void sum(int a,int b)
{ int ans=0;
    int precarry=0;
    while(a>0 && b>0 )
    {if( a%2==0 && b%2==0)
    { ans= ans*10 + precarry;
        precarry=0;
    }
    else if((a%2==0 && b%2==1) || (a%2==1 && b%2==0))
    { if(precarry==1)
        { ans=ans*10 + 0;
            precarry=1;
        }
        else
        {ans = ans*10 + 1;
        precarry=0;}
    }
    else
    { ans=ans*10 + precarry;
        precarry=1;
    }
    a/=10;
    b/=10;
    
} 
while(a>0)
{ if(precarry==1)
    { if(a%2==1)
        {ans=ans*10+0;
            precarry=1;
        }
        else
        { ans=ans*10+1;
            precarry=0;
        }
    }
    else
    { ans=ans*10 +(a%2);
        a/=10;
    }
}
while(b>0)
{ if(precarry==1)
    { if(b%2==1)
        {ans=ans*10+0;
            precarry=1;
        }
        else
        { ans=ans*10+1;
            precarry=0;
        }
    }
    else
    { ans=ans*10 +(b%2);
        b/=10;
    }
}
if(precarry==1)
{ans=ans*10 +1;}
int c=reverse(ans);
    cout<<c;
}
int main() {
	// your code goes here
	int a, b;
	cin>>a>>b;
	sum(a,b);
	return 0;
}
