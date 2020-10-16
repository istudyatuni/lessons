// 25
#include <iostream>
using namespace std;
int main(){
	float a, p = 1;
	int n, j = 0;
	cout << "a, n: ";
	cin >> a >> n;
	while (a - j * n < 1000 && a - (j + 1) * n >= 1000){
		p *= (a - j * n);
		j++;
	}
	if (j == 0)
		cout << "not exist";
	else
		cout << p;
	system("pause");
	return 0;
}