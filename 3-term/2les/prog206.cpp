//find max among k * e^( (sin(k+1))^2 ):[1, n] and their sum
#include <iostream>
#include <cmath>
using namespace std;
const double e = 2.718281828;
int main()
{
	unsigned n;
	cout << "enter n: ";
	cin >> n;
	double sum = 0, ad, ad_max = 1;
	cout << "   k ad      ad_max  sum\n";
	for (double k = 1; k <= n; k++) {
		ad = k * pow(e, (sin(k + 1)*sin(k + 1)));//current addend
		if (ad > ad_max)
			ad_max = ad;
		sum += ad;
		cout << "   " << k << ' ' << ad << ' ' << ad_max << ' ' << sum << endl;
	}
	cout << "\nsum = " << sum << endl;
	cout << "max addend = " << ad_max << endl;
	system("pause");
	return 0;
}
