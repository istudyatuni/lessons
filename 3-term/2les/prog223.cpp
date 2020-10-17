//есть a1..an, a1>0 и a(n+1)<0, n заранее не известно. Найти
// г) min(a1+a2, a2+a3, . . , a(n-1)+an)
// д) max(a1, a1*a2, . . , a1*a2*..*an)
#include <iostream>
using namespace std;
int main()
{
	int a = 1, i = 1, dv = 1, mx, mn, a_last = 0;
	cout << "first number must be greater than 0!\n";
	while (a >= 0) {
		cout << "enter a" << i << ": ";
		cin >> a;
		if (i == 1)
			mx = a;
		if (i == 2)
			mn = a + a_last;
		if (i == 1 && a <= 0) { //a1 > 0
			cout << "Are you fool? Try again\n";
			system("pause");
			return 1;
		}
		if (a < 0)break;//for not reinitialisation max and min
		dv *= a;
		// g //
		if (i > 1 && (a + a_last) < mn)
			mn = a + a_last;
		a_last = a;
		// d //
		if (a != 0 && dv > dv / a)
			mx = dv;
		i++;
	}
	cout << "min = " << mn << endl;
	cout << "max = " << mx << endl;
	system("pause");
	return 0;
}
