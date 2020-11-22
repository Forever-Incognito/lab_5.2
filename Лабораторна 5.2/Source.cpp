//lab_5.2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double S(const double x, const double eps, int& n, double s);
double A(const double x, const int n, double a);


int main()
{
    double xp, xk, x, dx, eps, Pi = acos(-1.), s = 0;
    int n = 0;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;
    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "     |"
        << setw(10) << "atan(x)" << "   |"
        << setw(7) << "S" << "      |"
        << setw(5) << "n" << "   |" << endl;
    cout << "-------------------------------------------------" << endl;

    x = xp;
    while (x <= xk + eps) {
        n = 0;
        s = S(x, eps, n, s);

        cout << "|" << setw(7) << setprecision(2) << x << "   |"
            << setw(10) << setprecision(5) << atan(x) << "   |"
            << setw(10) << setprecision(5) << s + Pi / 2 << "   |"
            << setw(5) << setprecision(0) << n << "   |" << endl;
        x += dx;
    }

    cout << "-------------------------------------------------" << endl;

    cin.get();
    return 0;

}

double S(const double x, const double eps, int& n, double s) {
    double a = -1 / x;
    s = a;
    do {
        n++;
        a = A(x, n, a);
        s += a;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, int n, double a) {
    double R = (-1 * (2.0 * n - 1)) / ((2.0 * n + 1) * x * x);
    a *= R;
    return a;
}