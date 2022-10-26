#include <iostream>
using namespace std;
#define f(x, y) float((y * y - x * x) / (y * y + x * x))
// #define f(x,y) (y*y-x*x)/(y*y+x*x)int

int main()
{

    float x0, y0, xn, h, yn, k1, k2, k3, k4, k;
    int i, n;

    cout << "Enter Initial Condition\n"
         << "x0= ";
    cin >> x0;
    cout << "y0= ";
    cin >> y0;
    cout << "Enter the calculation point xn= ";
    cin >> xn;
    cout << "\nEnter the number of steps: ";
    cin >> n;

    cout << "nx0 ty0 tyn\n";
    cout << "-------------------------------------\n";

    for (i = 0; i < n; i++)
    {
        k1 = h * (f(x0, y0));
        k2 = h;
        k3 = h * (f((x0 + h / 2), (y0 + k2 / 2)));
        k4 = h * (f((x0 + h), (y0 + k3)));

        k = (k1 + k2 + k3 + k4) / 6;
        yn = y0 + k;

        cout << x0 << "\t" << y0 << "\t" << yn << "\n";
        x0 = x0 + h;
        y0 = yn;
    }

    cout << "\n Value of y at x= " << xn << " is " << yn;

    return 0;
}
