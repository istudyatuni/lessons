#include <iostream>
using namespace std;
int main(){
	float x, y;
	cout << "x, y: ";
	cin >> x >> y;
	if (x > 0)
		if (y > 0)
			cout << "I quarter";
		else if (y < 0)
			cout << "IV quarter";
		else cout << "y = 0";
	else if (x < 0)
		if (y > 0)
			cout << "II quarter";
		else if (y < 0)
			cout << "III quarter";
		else cout << "y = 0";
	else cout << "  x = 0";
	return 0;
}