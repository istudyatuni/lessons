//sin x + (sin x)^2 + . . . + (sin x)^n
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	float x;
	cout << "enter x, n: ";
	cin >> x >> n;
	float sinx = sin(x), sum = 0, pr = sin(x);
	cout <<"n sum\t(sin x)^n" << endl;
	for (int i = 1; i <= n; i++) {
		sum += pr;
		cout << i << ' ' << sum << ' ' << pr << endl;
		if (i < n)
			pr *= sinx;
	}
	cout << "sum = " << sum << endl;
	cout << "(sin " << x << ")^" << n << " = " << pr << endl;
	system("pause");
}
