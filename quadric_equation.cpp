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
 float a,b,c,D,real_part,imag_part;
 cin>>a>>b>>c;
 D = (b*b)-(4*a*c);
 if(D==0){
     cout<<"Roots are Equal \n";
     real_part=(-b)/(2*a);
     cout<<"Root1 = Root2 is "<<real_part;
 }
 else if(D>0){
    float x1 = (-b + sqrt(D)) / (2*a);
    float x2 = (-b - sqrt(D)) / (2*a);
        cout << "Roots are real and different." << endl;
        cout << "Root1 = " << x1 << endl;
        cout << "Root2 = " << x2 << endl;
 }

 else{
     real_part = -b/(2*a);
        imag_part =sqrt(-D)/(2*a);
        cout << "Roots are complex and different."  << endl;
        cout << "Root1 = " << real_part << "+" << imag_part << "i" << endl;
        cout << "Root2 = " << real_part << "-" << imag_part << "i" << endl;
 }
 
 
 
return 0 ;
 
 
 } 