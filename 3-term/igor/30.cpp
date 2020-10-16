#include <iostream>
#include <cmath>
using namespace std;
int main(){
	float x, s = 0;
	int n;
	cout << "n, x: ";
	cin >> n >> x;
	for (int i = 1; i <= n; ++i){
		s += (pow(-1, i) * pow(x, i + 1));
	}
	cout << s;
	return 0;
}