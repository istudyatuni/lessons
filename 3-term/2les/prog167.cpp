#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float x1 = 2, y1 = 2, x2 = 1, y2 = 1, xi, yi, fct = 2;//x1 = x(i-1)
	int s = 16;
	cout << "167a_______________________________________|167b________________\n";
	cout << "xi___________________|yi___________________|yi/(i+1)____________\n";
	cout << "x1 = 1               |y1 = 1               |y1/2 = 0.5\n";
	cout << "x2 = 2               |y2 = 2               |y2/3 = " << left << float(2) / 3 << endl;
	for (float i = 3; i < 26; i++) {
		xi = (y1 - y2) / i;
		fct *= i;
		yi = (x1*x1 + x2 + y1) / fct;
		x2 = x1;
		y2 = y1;
		x1 = xi;
		y1 = yi;
		// a //
		if (i == 10)
			s--;
		cout << left << "x" << left << i << left << " = " << setw(s) << left << xi << '|';
		cout << left << "y" << left << i << left << " = " << setw(s) << left << yi << '|';
		// b //
		cout << left << "y" << left << i << left << "/" << left << i + 1;
		cout << left << " = " << left << yi / (i + 1) << endl;
	}
	return 0;
}
