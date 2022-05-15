#include <bits/stdc++.h>
using namespace std;
bool cond (int &a)
{ return (a>4);}
int main() {
	// your code goes here
	forward_list<int> li {1,2,2,3,3,4,5};
	forward_list<int>:: iterator itr;
	//li.remove(1);
	li.unique();
	/*li.insert_after(li.begin(),4);
	li.insert_after(li.before_begin(),0);
	li.reverse();*/
	li.remove_if(cond);
	for(itr=li.begin();itr!=li.end();itr++)
	cout<<(*itr)<<" ";
	return 0;
}
