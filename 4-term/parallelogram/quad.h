#include <iostream>
#include <cmath>
using namespace std;


#ifndef QUAD_H
#define QUAD_H

class Quadrangle {
protected:
    double x[4], y[4];
    double length(int a, int b) {
        //длина стороны между точками a и b
        if (a < 4 && a >= 0 && b < 4 && b >= 0)
           return sqrt((x[a] - x[b]) * (x[a] - x[b]) +
                        (y[a] - y[b]) * (y[a] - y[b]));
        else return 0;
    }
    double isMax() {
        double mx = 0;
        for (int i = 0; i < 4; ++i) {
            if (length(i, (i + 1) % 4) > mx) {
                mx = length(i, i + 1);
            }
        }
        return mx;
    }
    int isExist() {
        //если совпадают хотя бы две координаты
        for (int i = 0; i < 4; ++i) {
            for(int j = i + 1; j < 4; ++j){
                if (x[i] == x [j] && y[i] == y[j]) {
                    return 0;
                }
            }
        }
        if (onLine(0, 1, 2) || onLine(1, 2, 3) ||
            onLine(2, 3, 0) || onLine(3, 0, 1)) {
            return 0;
        }
        if (isMax() < (perimeter() - isMax()) ) {
            return 1;
        }
        return 0;
    }
    int onLine(int a, int b, int c) {
        //лежит ли точка b на одной линии с a и c (a--b--c)
        if (x[a] == x[b] && x[b] == x[c]) {
            return 1;
        }
        if (y[a] == y[b] && y[b] == y[c]) {
            return 1;
        }
        if (y[a] / x[a] == y[b] / x[b] && y[b] / x[b] == y[c] / x[c]) {
            return 1;
        }
        return 0;
    }
public:
    Quadrangle();
    Quadrangle(int) {
        input();
    }
    Quadrangle(double x1, double x2, double x3, double x4,
                double y1, double y2, double y3, double y4):
                 x{x1, x2, x3, x4}, y{y1, y2, y3, y4} {
        if (!isExist()) {
            cout << "quadrangle with these coordinates does not exist\n";
            input();
        }
    }
    void input() {
        cout << "enter 4 pairs coordinates (x, y):\n";
        for (int i = 0; i < 4; ++i) {
            cin >> x[i] >> y[i];
        }
        while (!isExist()) {
            cout << "NOT EXIST!\n";
            input();
        }
    }
    void print() {
        cout << "quadrangle: ";
        for (int i = 0; i < 4; ++i) {
            cout << " (" << x[i] << ", " << y[i] << "),";
        }
        cout << "\x8 \n";// \x8 is backspace
    }
    double perimeter() {
        return length(0, 1) + length(1, 2) + length(2, 3) + length(3, 0);
    }
    double area() {
        double a = length(0, 1), b = length(1, 2);
        double c = length(2, 3), d = length(3, 0);
        double p = (a + b + c + d) / 2;//полупериметр
        return sqrt((p - a) * (p - b) * (p - c) * (p - d));
    }
    double lengthSide(int i) {
        return length(i, (i + 1) % 4);
    }
    double lengthDiagonal(int i) {
        return length(i % 4, (i + 2) % 4);
    }
};

#endif // QUAD_H
