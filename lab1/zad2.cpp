#include <iostream>
#include <cmath>
#include <assert.h>
using namespace std;

enum Result { 
    circleInSquare, 
    squareInCircle, 
    intersection 
};

Result check(double l, double s) {
    double diameter = l / M_PI;
    double side = sqrt(s);

    if (diameter <= side) {
        return circleInSquare;
    } else if (side * sqrt(2) <= diameter) {
        return squareInCircle;
    } else {
        return intersection;
    }
    
}

int main() {
    double l, s;
    cout << "Введите длину окружности l: ";
    cin >> l;
    cout << "Введите площадь квадрата s: ";
    cin >> s;

    int res = check(l, s);

    switch (res)
    {
    case circleInSquare:
        cout << "Окружность полностью помещается внутрь квадрата." << endl;
        break;
    case squareInCircle:
        cout << "Квадрат полностью помещается внутрь окружности." << endl;
        break;
    case intersection:
        cout << "Окружность и квадрат пересекаются." << endl;
        break;
    default:
        break;
    }

    assert(check(1, 100) == circleInSquare);
    assert(check(10, 5) == squareInCircle);
    assert(check(37, 100) == intersection);
    cout << "--------------------------\nТесты пройдены";

    return 0;
}