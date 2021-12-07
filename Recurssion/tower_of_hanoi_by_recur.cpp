#include <bits/stdc++.h>
using namespace std;
void towerofhanoi(int n,char src,char dest,char help)
{ if(n==0)
    return;
    towerofhanoi(n-1,src,help,dest); //this will tranfer n-1 hoops to helper rod as it is destination
    cout<<"Move from "<<src<<" to "<<dest<<"\n";
    towerofhanoi(n-1,help,dest,src); //this will tranfer all hoops to destination rod from helper rod.
}
int main() {
	// your code goes here
	ios::sync_with_stdio(0);
	towerofhanoi(3,'A','C','B');
	return 0;
}
