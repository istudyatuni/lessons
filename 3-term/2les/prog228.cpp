//дано натуральное n, действительные числа a[1..n]
//выяснить, является ли последовательность упорядоченной по убыванию
#include <iostream>
using namespace std;
int main()
{
	unsigned n;
	float a, a_last;
	bool key = 1;
	cout << "enter n > 0 : ";
	cin >> n;
	cout << "enter a1: ";
	cin >> a_last;
	for (int i = 2; i <= n; i++) {
		cout << "enter a" << i << ": ";
		cin >> a;
		if (a > a_last)
			key = 0;
		a_last = a;
	}
	if (key)
		cout << "yes\n";
	else cout << "no\n";
	system("pause");
	return 0;
}