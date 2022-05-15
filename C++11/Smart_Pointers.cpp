#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using op_set = tree<T,null_type,less<T>,
rb_tree_tag,tree_order_statistics_node_update>; 
 
 class rectangle{
  private:
  int length;
  int breadth;

  public:
  rectangle(int l,int b){
      length=l;
      breadth=b;
  }

  int area(){
      return length*breadth;
  }

  int perimeter(){
      return (2*(length+breadth));
  }

  int volume(){
      return length*breadth*length;
  }

 };
 
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 unique_ptr<rectangle> ptr(new rectangle(10,5)); // Only one pointer at a time can point to object;

 cout<<ptr->area()<<"\n";

 unique_ptr<rectangle> ptr1;
 ptr1=move(ptr);

 cout<<ptr1->area();
 cout<<endl;
 shared_ptr<rectangle> p(new rectangle(20,10));
 cout<<p->perimeter();
 cout<<endl;
 shared_ptr<rectangle> p1(p);
 cout<<p1->perimeter();
 cout<<endl;
 shared_ptr<rectangle> p2(p1);
 cout<<p2->perimeter();
 cout<<endl;
 shared_ptr<rectangle> p3(p);
 cout<<p2->volume();
 
 cout<<"\n"<<p2.use_count();
 
 
 
return 0 ;
 
 
 } 