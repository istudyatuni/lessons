// det_recursion.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
int determinate(int s, vector <int> a);
int main() {
	ifstream f("input.txt");
	int n;
	f >> n;
	cout << "n = " << n << "\nmatrix:\n";
	vector <int> det(n*n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			f >> det[i*n + j];
			cout << det[i*n + j] << ' ';
		}
		cout << '\n';
	}
	int res = determinate(n, det);
	cout << "determinate = " << res << '\n';
	system("pause");
	f.close();
	return 0;
}
int determinate(int s, vector <int> a) {
	if (s == 2) {//end recursion
		return a[0] * a[3] - a[1] * a[2];
	}
	int res = 0;
	for (int i = 0; i < s; ++i) {//search det
		vector<int> b; //minor
		//decomposition without 0 row and i column
		for (int j = 1; j < s; ++j) {//write minor to b, j is row
			for (int k = 0; k < s; ++k)//run by columns
				if (k != i)
					b.push_back(a[j*s + k]);
				else;
		}
		res += a[i] * determinate(s - 1, b)*pow(-1, i);
	}
	return res;
}
