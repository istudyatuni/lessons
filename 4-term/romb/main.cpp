#include <iostream>
#include <cmath>
//#define PI 3.14159265
using namespace std;
void pause () {
    char a;
    cin >> a;
    return;
}
double PI = 3.14159265;
double mod180 (double a) {
	while (a > 180) {
		a -= 180;
	}
	return abs(a);
}
class romb {
	double n, ang;
public:
	romb() {
		n = 0;
		ang = 0;
	}
	romb(double a, double b) {
		n = a;
		ang = mod180(b);
	}
	romb(bool) {
		double a, b;
		cin >> a >> b;
		(*this) = {a, b};
	}
	friend ostream& operator<<(ostream&, romb&);

	double square () {
		return n * n * sin(ang * PI / 180);
	}
};
ostream& operator<<(ostream& os, romb& a) {
	cout << "a = " << a.n << ", angle = " << a.ang;
	return os;
}
int main()
{
	romb a, b(4, 65), c(true);
	cout << a << ", square = " << a.square() << endl;
	cout << b << ", square = " << b.square() << endl;
	cout << c << ", square = " << c.square();
	pause();
	return 0;
}
