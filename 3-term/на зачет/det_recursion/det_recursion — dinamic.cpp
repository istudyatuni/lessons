// det_recursion.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;
int determinate (int n, int** a);
int main() {
	ifstream f("input.txt");
	int n;
	f >> n;
	cout << "n = " << n << "\nmatrix:\n";
	int **a = new int* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[n];
		for (int j = 0; j < n; ++j) {
			f >> a[i][j];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "j k p";
	int res = determinate(n, a); //-376
	cout << "determinate = " << res << '\n';
	system("pause");
	f.close();
	return 0;
}
int determinate (int n, int** mat){
	cout << "\nnew call, n = " << n << '\n';
	int res = 0;
	if (n == 2) { //end recursion
		res = mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
		cout << "\ndet2 = " << res << '\n';
		return res;
	}
	for (int i = 0; i < n; ++i) {//search det
		int** b = new int* [n - 1]; //minor
		for (int j = 0; j < n - 1; ++j)
			b[j] = new int[n - 1];
		//decomposition without 0 row and i column
		for (int j = 1; j < n; ++j) {//write minor to b, j is row
			int s = 0, p = 0;
			for (int k = 0; k < n; ++k)//run by columns
				if (k != i){
					b[s][p] = mat[j][k];
					//cout << j << '.' << k << '.' << p << '\n';
					cout << b[s][p] << ' ';
					p++;
				}
			cout << '\n';
			s++;
		}
		res += mat[0][i] * determinate(n - 1, b)*pow(-1, i);
		delete[]b;
	}
	return res;
}