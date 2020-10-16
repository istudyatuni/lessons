#include <iostream>
using namespace std;
class Ellipse {
    double a, b;
public:
    Ellipse(): a{0}, b{0}{}
    Ellipse(int) {
        cout << "> ";//чтобы понять, что надо что то вводить
        cin >> a >> b;
    }
    Ellipse(double a, double b): a{a}, b{b}{}
    void print() {
        cout << a << 'x' << b << ", area = " << area() << endl;
    }
    double area() {
        return a * b * 3.1416;
    }
};
int main() {
    Ellipse a, b(5), c(4.5, 56);
    a.print();
    b.print();
    c.print();
}