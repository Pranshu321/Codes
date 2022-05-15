#include <bits/stdc++.h>
using namespace std;
union same {
    int i;
    float f;
long l;
    }data,data1;
int main() {
	// your code goes here
	cout<<"\n memory of the union variables are : "<<sizeof(data)<<" "<<sizeof(data1);
	cout<<endl<<sizeof(int);
	return 0;
}
