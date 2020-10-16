// cramer_rule.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;
int determinate(int s, vector <int> a);
int main()
{
	ifstream f("input.txt");
	int n;
	f >> n;
	cout << "n = " << n << '\n';
	vector <int> matrix;
	vector <int>b;
	cout << "source matrix:\n";
	for (int i = 0; i < n; ++i) {
		int a;
		for (int j = 0; j < n; ++j) {
			f >> a;
			matrix.push_back(a);
			cout << matrix[i*n + j] << ' ';
		}
		f >> a;
		b.push_back(a);
		cout << "= " << b[i] << '\n';
	}
	f.close();
	double det = determinate(n, matrix);
	cout << "det = " << det << "\nsolution:\n";
	if (det == 0) {
		cerr << "ERROR: determinate = 0!";
		cin.get();
		return 1;
	}
	vector <double>x(n); //solution
	for (int i = 0; i < n; ++i) {
		vector<int>tmp;
		tmp = matrix;
		for (int j = 0; j < n; ++j) {
			tmp[j*n + i] = b[j];
		}
		x[i] = determinate(n, tmp) / det;
		cout << i << ": " << determinate(n, tmp) << '\n';
		//cout << "x[" << i << "] = " << x[i] << '\n';
	}
	for (int i = 0; i < n; ++i) {
		cout << "x[" << i << "] = " << x[i] << '\n';
	}
	system("pause");
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
