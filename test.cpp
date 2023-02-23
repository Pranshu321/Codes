#include <iostream>
using namespace std;
double a[4][4];
double b[4][4];

void insert(double x[4][4])
{
    double val;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> val;
            x[i][j] = val;
        }
    }
}
double cal11(double x[4][4])
{
    return (x[1][1] * x[1][2]) + (x[1][2] * x[2][1]);
}
double cal21(double x[4][4])
{
    return (x[3][1] * x[4][2]) + (x[3][2] * x[4][1]);
}

double cal12(double x[4][4])
{
    return (x[1][3] * x[2][4]) + (x[1][4] * x[2][3]);
}

double cal22(double x[4][4])
{
    return (x[2][3] * x[1][4]) + (x[2][4] * x[1][3]);
}

int main()
{
    double a11, a12, a22, a21, b11, b12, b21, b22, a[4][4], b[4][4];
    double p, q, r, s, t, u, v, c11, c12, c21, c22;
    // insert values in the matrix a
    cout << "\n a: \n";
    insert(a);
    // insert values in the matrix a
    cout << "\n b: \n";
    insert(b);

    // dividing single 4x4 matrix into four 2x2 matrices
    a11 = cal11(a);
    a12 = cal12(a);
    a21 = cal21(a);
    a22 = cal22(a);
    b11 = cal11(b);
    b12 = cal12(b);
    b21 = cal21(b);
    b22 = cal22(b);

    // assigning variables acc. to strassen's algo
    p = (a11 + a22) * (b11 + b22);
    q = (a21 + a22) * b11;
    r = a11 * (b12 - b22);
    s = a22 * (b21 - b11);
    t = (a11 + a12) * b22;
    u = (a11 - a21) * (b11 + b12);
    v = (a12 - a22) * (b21 + b22);

    // outputting the final matrix
    cout << "\n final matrix";
    cout << "\n"
         << p + s - t + v << " " << r + t;
    cout << "\n"
         << q + s << " " << p + r - q + u;
    return 0;
}