//комплексное число a = x + y * i
#include <iostream>
#include <cmath>
using namespace std;
class complx {
		// a = x + y * i
	double x, y;
public:
	complx(double a = 0, double b = 0) {
		x = a;
		y = b;
	}
	complx(const complx& a) {
		x = a.x;
		y = a.y;
	}
	void rewrite(double a, double b) {
		x = a;
		y = b;
	}
	friend double abs(complx&);
	friend void root(complx&, int);

	complx operator+() {//унарный плюс
		return complx(*this);
	}
	complx operator-() const {//сопряженное, унарный минус
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
		complx tmp = -a;//a =
		*this = *this * tmp;//con;//numerator, умножаем на сопряженное к знаменателю
		x /= den;
		y /= den;
		return *this;
	}
	complx operator/(const complx& a) const {
		return complx(*this) /= a;
	}

	//префиксный инкремент увеличивает Re, постфиксный - Im
	complx& operator++() {
		x++;
		return *this;
	}
	complx& operator++(int) {
		y++;
		return *this;
	}

	friend ostream& operator<<(ostream&, const complx&);
};
ostream& operator<<(ostream& os, const complx& a) {
	if (a.y < 0) {
		os << a.x << a.y << 'i';
		return os;
	}
	if (a.x == 0 && a.y == 0) {
		os << 0;
		return os;
	}
	if (a.x == 0) {
		os << a.y << 'i';
		return os;
	}
	if (a.y == 0) {
		os << a.x;
		return os;
	}
	os << a.x << '+' << a.y << 'i';
	return os;
}
double abs(complx& a) {
	return sqrt(a.x * a.x + a.y * a.y);
}
void root(complx& a, int n) {
	if (n == 1)
		return;
	//trigonometric form
	double ab = abs(a);
	double arg = atan(a.y / a.x) * 180 / 3.1416;
	//output
	cout << "root of degree " << n << " from " << a;
	cout << " = " << pow(ab, 1 / n) << " * (cos((";
	cout << arg << " + 2*pi*k) / " << n << ") + i*sin((";
	cout << arg << " + 2*pi*k) / " << n << "), k = 0";
	if (n > 1)
		cout << " .. " << n - 1;
}
int main() {
	complx a1(5, 2), b1(2, -5);
	//test
	//cout << a1 + b1 << endl << a1 - b1 << endl << a1 * b1 << endl << a1 / b1 << endl;
	//cout << "increment:\n";
	//cout << ++a1++ << endl;
	//cout << abs(a1);
	root(a1, 5);
	return 0;
}