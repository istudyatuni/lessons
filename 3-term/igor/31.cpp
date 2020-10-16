#include <iostream>
using namespace std;
int main(){
	float x, p = 1;
	int n;
	cout << "n, x: ";
	cin >> n >> x;
	x *= x;
	cout << "x^2 = " << x << '\n';
	for (int i = 1; i <= n; ++i)
		p *= (x / (x + 2));
	cout << p;
	return 0;
}