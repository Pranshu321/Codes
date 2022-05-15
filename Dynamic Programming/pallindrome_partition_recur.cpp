#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//recurssion
bool isPalindrome(string s, int i, int j)
{
    while(i < j)
    {
      if(s[i] != s[j])
        return false; 
      i++;
      j--;
    }
    return true;
}
int min_Partion(string s, int i, int j)
{
    if( i >= j || isPalindrome(s, i, j) )
      return 0;
    int ans = INT_MAX, count;
    for(int k = i; k < j; k++)
    {
      count = min_Partion(s, i, k) + min_Partion(s, k + 1, j) + 1;
  
      ans = min(ans, count);
    }
    return ans;
}
int32_t main() {
	// your code goes here
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	string s;
	cin>>s;
	int n=s.length();
	cout<<min_Partion(s,0,n-1);
	
	
	return 0;
}