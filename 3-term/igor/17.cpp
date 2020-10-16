#include <iostream>
using namespace std;
float calc(float x, float y){
	return (2 * (x * x * x + 2) + x * (y * y * y + 3)) / (6 + 5 * y * y + x * x);
}
int main(){
	float x, y;
	cout << "x, y: ";
	cin >> x >> y;
	cout << calc(x, y);
	return 0;
}