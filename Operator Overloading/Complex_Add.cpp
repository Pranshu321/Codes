#include <bits/stdc++.h>

using namespace std;

#define ll long long int

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using op_set = tree<T, null_type, less<T>,
                    rb_tree_tag, tree_order_statistics_node_update>;
class Complex
{
public:
    int real;
    int img;

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
};
int main()

{
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    Complex c1, c2, c3;
    c1.real = 5;
    c1.img = 4;
    c2.real = 10;
    c2.img = 5;

    c3 = c1 + c2;
    cout << c3.real << "+i" << c3.img << "\n";

    return 0;
}

/*
Operator overloading
• Operators can be overloaded on our classes
• We can define operator for our own classes
• Operators can be overloaded using member functions or friend functions
• Global functions can also access private and protected members of an object if they are
declared as friend inside a class
*/