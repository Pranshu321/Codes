#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
#include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
int main () 
{ 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 
 [](){cout<<"This is the first Lambda function \n";}();

 [](int a,int b){cout<<"Minus is : "<<abs(a-b)<<endl;}(10,30);

 int a= [](int a,int b)->int{return a+b;}(20,34);
 cout<<a<<"\n";
 
 int x=10;
 int y=40;
 float z=4.5;

 [&x,&y,&z](){cout<<y-x+z;}();

 [&](){cout<<"\n"<<y-x+z;}();
 
 
 
 return 0 ;
 
 
} 
 