//комплексное число a = x + y * i
#include <iostream>
#include <cmath>
using namespace std;
class complx {
        // a = x + y * i
    double x, y;
    complx conjugate() {//сопряженное
        complx res(x, -y);
        return res;
    }
public:
    complx(double a = 0, double b = 0) {
        x = a;
        y = b;
    }
    void rewrite(double a, double b) {
        x = a;
        y = b;
    }
    double modul() {
        return sqrt(x * x + y * y);
    }
    complx operator+() {//унарный +
        return complx(*this);
    }
    complx operator-() const {//сопряженное, унарный -
        complx res(*this);
        res.x = x;
        res.y = -y;
        return res;
    }

    //сложение
    complx& operator+=(const complx& a) {
        x += a.x;
        y += a.y;
        return *this;
    }
    complx operator+(const complx& a) const {
        return complx(*this) += a;
    }

    //вычитание
    complx& operator-=(const complx& a) {
        x -= a.x;
        y -= a.y;
        return *this;
    }
    complx operator-(const complx& a) const {
        return complx(*this) -= a;
    }

    //умножение
    /*complx& operator*=(const complx& a) {
        x = x * a.x - y * a.y; //work not correct
        y = x * a.y + y * a.x;
        return *this;
    }
    complx operator*(const complx& a) const {
        return complx(*this) *= a;
    }*/
    complx operator*(const complx& a) {
        complx res(x * a.x - y * a.y, x * a.y + y * a.x);
        return res;
    }

    //деление
    complx operator/=(const complx& a) {
        //complx tmp = a;
        //complx con = tmp.conjugate();
        double den = a.x * a.x + a.y * a.y;//a^2 - b^2 (i^2 = -1), denominator
        a = -a;
        *this = *this * a;//con;//numerator, умножаем на сопряженное к знаменателю
        x /= den;
        y /= den;
        return *this;
    }
    complx operator/(const complx& a) const {
        return complx(*this) /= a;
    }


    void out(){
        cout << x << " + " << y << " * i";
    }
};
int main() {
    complx a(13, 1), b(7, -6);
    cout << endl;
    (a / b).out();
    cout << endl;
    (a + b).out();
    cout << endl;
    (a - b).out();
    cout << endl;
    (a * b).out();
    return 0;
}
