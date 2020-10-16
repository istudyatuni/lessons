//найти все общие натуральные кратные чисел m и n, меньшие mn
#include <iostream>
using namespace std;
int main()
{
	unsigned m, n;
    std::cout << "enter m, n: ";
	cin >> m >> n;
	cout << "mn = " << m * n << endl;
	for (int i = 1; i < m*n; i++) {
		if (i%m == 0 && i%n == 0)
			cout << i << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}