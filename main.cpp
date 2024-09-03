#include <iostream>
#include <cmath>
#include <functional>

double bisection(std::function<double(double)> func, double a, double b, double tol) {
    double fa = func(a);
    double fb = func(b);
    double c, fc;

    if (fa * fb >= 0) {
        std::cerr << "A função deve ter sinais opostos nos pontos a e b." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }

    while ((b - a) / 2 > tol) {
        c = (a + b) / 2;
        fc = func(c);

        if (fc == 0.0) {
            break;
        } else if (fa * fc < 0) {
            b = c;
            fb = fc;
        } else {
            a = c;
            fa = fc;
        }
    }

    return (a + b) / 2;
}

int main() {
    std::cout << "Entre com os coeficientes da equação (ax^2 + bx + c = 0):" << std::endl;

    double a, b, c;
    std::cin >> a >> b >> c;

    auto func = [a, b, c](double x) {
        return a * x * x + b * x + c;
    };

    double erro;
    std::cout << "Entre com o erro esperado: ";
    std::cin >> erro;

    double x0, x1;
    std::cout << "Entre com o intervalo [x0, x1] onde a raiz está localizada: ";
    std::cin >> x0 >> x1;

    double raiz = bisection(func, x0, x1, erro);
    
    if (!std::isnan(raiz)) {
        std::cout << "A raiz aproximada é: " << raiz << std::endl;
    }

    return 0;
}
