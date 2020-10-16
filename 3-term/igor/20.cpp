#include <iostream>
using namespace std;
int main(){
	float x, y, z;
	cout << "x, y: ";
	cin >> x >> y;
	// если ввести два противоположных числа (5, -5), результат = inf (div by 0)
	if (x <= 0 && y <= 0)
		z = 0;
	else if ((x + y) > 0)
		z = x * x + y * y;
	else z = 1 / (x + y);
	cout << z;
	return 0;
}