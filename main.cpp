#include <iostream>
#include <cmath>
#include <functional>
#include <limits>

using namespace std;

double bisection(function<double(double)> func, double a, double b, double tol) {
    double fa = func(a);
    double fb = func(b);
    double c, fc;

    if (fa * fb >= 0) {
        cerr << "A função deve ter sinais opostos nos pontos a e b." << endl;
        return numeric_limits<double>::quiet_NaN();
    }

    while ((b - a) / 2 > tol) {
        c = (a + b) / 2;
        fc = func(c);

        if (fc == 0.0) {
            break;
        }
        else if (fa * fc < 0) {
            b = c;
            fb = fc;
        }
        else {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2;
}

int main() {
    cout << "Entre com os coeficientes da equação (ax^2 + bx + c = 0):" << endl;

    double a, b, c;

    cin >> a;
    cin >> b;
    cin >> c;

    auto func = [a, b, c](double x) {
        return a * x * x + b * x + c;
        };

    double erro;
    cout << "Entre com o erro esperado: ";
    cin >> erro;

    double x0, x1;
    cout << "Entre com o intervalo [x0, x1] onde a raiz está localizada: ";
    cin >> x0;
    cin >> x1;

    double raiz = bisection(func, x0, x1, erro);

    if (!isnan(raiz)) {
        cout << "A raiz aproximada é: " << raiz << endl;
    }

    return 0;
}
