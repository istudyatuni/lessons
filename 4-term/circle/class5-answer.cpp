#include <iostream>
#include <vector>
using namespace std;

class Circle {
protected:
    double r;
    const double Pi = 3.1416;
public:
    Circle(double r = 0):r(r){};
    void print() {
        cout << "\ncircle: R = " << r;
        cout << "\narea = " << area();
        cout << " circumference = " << circumference();
    }
    double area() {
        return Pi * r * r;
    }
    double circumference() {
        return 2 * Pi * r;
    }
    void input(int i) {
        cout << '\n' << i << ": ";
        cin >> r;
    }
};
class Cylinder: public Circle {
    double h;
public:
    Cylinder(double r = 0, double h = 0): Circle(r), h(h){};
    double area() {
        return Circle::area() * 2 + h * circumference();
    }
    double volume() {
        return Circle::area() * h;
    }
    void print() {
        cout << "\ncylinder: R = " << r << ", H = " << h;
        cout << "\narea = " << area();
        cout << " volume = " << volume();
        cout << " circumference = " << circumference();
    }
    void input(int i) {
        cout << '\n' << i << ": ";
        cin >> r >> h;
    }
};
int main() {
    vector<Circle> circ;
    vector<Cylinder> cyl;
    cout << "enter n and m: ";
    int n, m;
    cin >> n >> m;
    cout << "Enter circles:\n";
    for (int i = 0; i < n; ++i) {
        Circle tmp;
        tmp.input(i);
        circ.push_back(tmp);
        circ[i].print();
    }
    cout << "\nEnter cylinders:";
    for (int i = 0; i < m; ++i) {
        Cylinder tmp;
        tmp.input(i);
        cyl.push_back(tmp);
        cyl[i].print();
    }

    double max_s = circ[0].area(), mid_vol = 0;
    int j = 0;
    for (int i = 1; i < n; ++i) {
        if (circ[i].area() > max_s) {
            max_s = circ[i].area();
            j = i;
        }
    }
    cout << "\ncircle with max area is with index " << j << '\n';
    circ[j].print();
    for (int i = 0; i < m; ++i) {
        mid_vol += cyl[i].volume();
    }
    mid_vol /= m;
    cout << "\nmiddle cylinder's volume = " << mid_vol;
    return 0;
}
