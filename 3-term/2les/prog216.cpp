//даны целые числа с1..с95 Имеются ли в последовательности а) два идущих подряд
//нулевых члена б) три нулевых подряд
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
int main()
{
	srand(time(0));
	int z2 = 0, z3 = 0, c, c1 = 1, c2 = 1;//c2=c(i-2)
	for (int i = 1; i <= 95; i++) {
		//cout << "enter c" << i << ": ";  //if manual input
		c = rand() % 5;
		cout << c;
		if (c == 0 && c1 == 0 && c2 == 0)
			z3 = 1;
		if (c == 0 && c1 == 0)
			z2 = 1;
		c2 = c1;
		c1 = c;
	}
	cout << "\n2 zero in a row: ";
	if (z2)
		cout << "yes\n";
	else cout << "no\n";
	cout << "3 zero in a row: ";
	if (z3)
		cout << "yes\n";
	else cout << "no\n";
	system("pause");
	return 0;
}