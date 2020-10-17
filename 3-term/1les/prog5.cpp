//cos1*(cos1+cos2)*...*(cos1+cos2+..+cosn)
//div
//sin1*(sin1+sin2)*...
#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float n;
	cout << "enter n: ";
	cin >> n;
	float ch = 1, zn = 1, cosx = 0, sinx = 0;
	cout << "i|cos1+.+cosi sin1+.+sini ch\t   zn   cosi     sini\n";
	for (float i = 1; i <= n; i++) {
		cosx += cos(i);
		sinx += sin(i);
		ch *= cosx;
		zn *= sinx;
		cout << i << '|' << cosx << ' ' << sinx << ' ' << ch << ' ' << zn;
		cout << ' ' << cos(i) << ' ' << sin(i) << endl;
	}
	cout << "result = " << ch / zn << endl;
	system("pause");
}
