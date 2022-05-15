#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
template<class T>
class arthimetic{
  T a ,b;
  public :
arthimetic(T a,T b){
      this->a=a;
      this->b=b;
 }
  T add();
  T sub();
};
template<class T>
T arthimetic<T>::add(){
    T c;
    c=a+b;
    return c;
}
template<class T>
T arthimetic<T>::sub(){
    T c;
    c=abs(a-b);
    return c;
}

 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 arthimetic<double> a1(10,5);
 cout<<a1.add()<<"\n";
 arthimetic<float> v(1.2,1.7);
 cout<<v.sub()<<"\n";
 
 
 
 
return 0 ;
 
 
 } 