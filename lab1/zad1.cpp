#include <iostream>
#include <cmath>
using namespace std;

double radiansToDegrees(double angle) {
    return angle*M_PI/180;
}

pair<unsigned int, unsigned int> findMinMaxValue(double x, int n) {
    pair<unsigned int, double> min = pair<unsigned int, double>(1, sin(x));
    pair<unsigned int, double> max = pair<unsigned int, double>(1, sin(x));

    for (int k = 2; k <= n; ++k) {
        double currentSin = pow(sin(x), k);

        if (currentSin < min.second) {
            min.first = k;
            min.second = currentSin;
        }

        if (currentSin > max.second) {
            max.first = k;
            max.second = currentSin;
        }
    }

    return pair<unsigned int, unsigned int>(min.first, max.first);
}

int main() {
    int n;
    double x;
    
    cout << "Введите целое положительное число n: ";
    cin >> n;

    cout << "Введите вещественное число x: ";
    cin >> x;

    x = radiansToDegrees(x);

    pair<unsigned int, unsigned int> res = findMinMaxValue(x, n);

    cout << "Номер наименьшего значения: " << res.first << endl;
    cout << "Номер наибольшего значения: " << res.second << endl;

    return 0;
}