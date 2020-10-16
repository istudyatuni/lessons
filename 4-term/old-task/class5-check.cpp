#include <iostream>
using namespace std;

class employee
{
private:
public:
    class date
    {
    private:
        int day,month,year;
    public:
        date():day(0),month(0),year(0)
        {};
 
        void adddate();
 
        void showdate()
        {
            cout << day << '/' << month << '/' << year << endl;
        }
    };
    date d1;
    int num_emp;
    float salary;
    employee():num_emp(0),salary(0.0)
    {};
 
    void gatemploye()
    {
        d1.adddate();
    }
 
    void putemploye()
    {
        d1.showdate();
    }
};
void employee::date::adddate() {
            cout << "Enter date dd/mm/yyyy: "; 
            cin >> day >> month >> year;
}
void foo() {
    class abc {
        int a, b;
    public:
        abc():a(0), b(0){};
        abc(int a, int b):a(a), b(b){};
        void print() {
            cout << a << '/' << b << '\n';
        }
        void operator=(const abc& t) {
            a = t.a;
            b = t.b;
        }
    };
    abc a, b(5, 6);
    a.print();
    a = b;
    a.print();
}
/*class triangle{
    int n; // размерность пространства
    float* a,*b,*c; // вершины треугольника
public:
triangle();
    triangle(int n, float x1, float y1, float x2, float y2,
            float x3, float y3):n(n) {
        a = new float[2];
        b = new float[2];
        c = new float[3];
        a[0] = x1; a[1] = y1;
        b[0] = x2; b[1] = y2;
        c[0] = x3; c[1] = y3;
    }
    void operator=(const triangle& t) {
        n = t.n;
        for (int i = 0; i < 2; ++i) {
        a[i] = t.a[i];
        b[i] = t.b[i];
        c[i] = t.c[i];
        }
    }
    ~triangle() {
        delete[]a;
        delete[]b;
        delete[]c;
    }
};*/
class circul{
    int n; // размерность пространства
    float* center; // центр окружности
    float* a; // точка, принадлежащая окружности
public:
    circul();
    circul(int n, float x1, float y1, float x2, float y2):n(n) {
        a = new float[2];
        center = new float[2];
        a[0] = x1; a[1] = y1;
        center[0] = x2; center[1] = y2;
    }
    void operator=(const circul& t) {
        n = t.n;
        for (int i = 0; i < 2; ++i) {
            a[i] = t.a[i];
            center[i] = t.center[i];
        }
    }
    ~circul() {
        delete[]a;
        delete[]center;
    }
};
int main()
{
    employee em1;
    employee::date b;
    foo();
    b.adddate();
    b.showdate();
    em1.gatemploye();
    em1.putemploye();
    return 0;
}
