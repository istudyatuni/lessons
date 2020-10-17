#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	float a = 1, b = 1, n, at, sum = 0;
	cout << "enter n: ";
	cin >> n;
	int fct = 1, ch = 2;
	for (int k = 1; k <= n; k++) {
		sum += ch / ((1 + a * a + b * b)  * fct);
		at = a;
		cout << 1 + a * a + b * b << endl;
		a = 3 * b + 2 * a;
		b = 2 * at + b;
		fct *= (k + 1);
		ch *= 2;
	}
	cout << "sum = " << sum << endl;
	system("pause");
}
