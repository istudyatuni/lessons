//sqrt( 3*1 + sqrt(3*2 + .. + sqrt(3*(n-1) + sqrt(3*n))..))
#include <iostream>
using  namespace std;
int main()
{
	float n;
	cout << "enter n: ";
	cin >> n;
	float res = 0, tmp;
	for (float i = n; i > 0; i--) {
		tmp = res;
		res = sqrt(3 * i + tmp);//sqrt from 3*i+sqrt, tmp is root(=res) from last step
		cout << i << ' ' << res << endl;
	}
	cout << "result = " << res << endl;
	system("pause");
}
