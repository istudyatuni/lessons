#include <iostream>

using namespace std;
class Time {
    int h, m, s;//hour, minute, second
public:
    Time(int a = 0, int b = 0, int c = 0) {
        int tmp = c / 60;
        s = c % 60;
        b += tmp;
        tmp = b / 60;
        m = b % 60;
        a += tmp;
        h = a % 24;
    }
    friend ostream& operator<<(ostream&, const Time&);

    Time& operator+=(const Time& a) {
        h = (h + a.h) % 24;
        m = (m + a.m) % 60;
        s = (s + a.s) % 60;
        return *this;
    }
    Time operator+(const Time& a) const {
        return Time(*this) += a;
    }

    Time& operator-=(const Time& a) {
        h = (h - a.h + 24) % 24;
        m = (m - a.m + 60) % 60;
        s = (s - a.s + 60) % 60;
        return *this;
    }
    Time operator-(const Time& a) const {
        return Time(*this) -= a;
    }

    int operator>(const Time& a) const {
        if (h > a.h) return 1;
        if (h == a.h && m > a.m) return 1;
        if (h == a.h && m == a.m && s > a.s) return 1;
        return 0;
    }
    int operator<(const Time& a) const {
        if (h < a.h) return 1;
        if (h == a.h && m < a.m) return 1;
        if (h == a.h && m == a.m && s < a.s) return 1;
        return 0;
    }
};
ostream& operator<<(ostream& os, const Time& a) {
    if (a.h < 10)
        cout << '0';
    cout << a.h << ':';
    if (a.m < 10)
        cout << '0';
    cout << a.m << ':';
    if (a.s < 10)
        cout << '0';
    cout << a.s << ", ";

    int n = a.h / 6;
    if (n == 0)
        cout << "night";
    else if (n == 1)
        cout << "morning";
    else if (n == 2)
        cout << "day";
    else
        cout << "evening";
    return os;
}
int main() {
    Time t1(1, 2, 3), t2(2, 3, 5), t3(7, 1, 9), t4(0, 1, 65);
    cout << t1 << '\n' << t2 << '\n' << t3 << '\n' << t4 << "\n\n";
    Time T1 = t1 + t3, T2 = t4 - t2;
    cout << T1 << '\n' << T2 << '\n';
    if (T1 > T2)
        cout << "more";
    if (T1 < T2)
        cout << "least";
    return 0;
}
