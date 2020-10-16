//даны числа a, n, x1 . . xn. каким по счету в последовательности x[1, n]
//идет член равный a
#include <iostream>
using namespace std;
int main()
{
	int a, n, k = 0, x;
	cout << "enter a, n: ";
	cin >> a >> n;
	for (int i = 1; i <= n; i++) {
		cout << i << ": ";
		cin >> x;
		if (x == a && k == 0)
			k = i;
	}
	cout << "subscript x equal a = " << k << endl;
	system("pause");
	return 0;
}