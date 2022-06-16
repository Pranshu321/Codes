#include<bits/stdc++.h>
 
 using namespace std;
 
 #define ll long long int
 
 #include <ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

 void Josh(vector<int> person, int k, int index)
{
    // Base case , when only one person is left
    if (person.size() == 1) {
        cout << person[0] << endl;
        return;
    }
 
    // find the index of first person which will die
    index = ((index + k) % person.size());
 
    // remove the first person which is going to be killed
    person.erase(person.begin() + index);
 
    // recursive call for n-1 persons
    Josh(person, k, index);
}
 int main () 
 
 { 
 ios_base:: sync_with_stdio(false);
 cout.tie(0);  cin.tie(0);
 vector<int>v;
 for(int i=1;i<=40;i++){
     v.push_back(i);
 }
 int k=7;
 int index=0;
 Josh(v,k-1,index);
//  cout<<ans; 
 
 
 
return 0 ;
 
 
 } 
