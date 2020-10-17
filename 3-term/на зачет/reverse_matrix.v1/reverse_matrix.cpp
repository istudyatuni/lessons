// reverse_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int determinate(int s, vector <int> a);
int main()
{
	ifstream f("input.txt");
	int n;
	f >> n;
	vector<int>matrix;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			f >> a;
			matrix.push_back(a);
			cout << matrix[i*n + j] << ' ';
		}
		cout << '\n';
	}
	f.close();
	cout << "det = " << determinate(n, matrix);
	//cout << "\nmatrix det:\n";
	cout << "\ndebug";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			vector<int>minor;
		//if i > 0, 1st i elements write not correct to minor
			for (int k = 0; k < n; ++k) {//write minor, k is row
				if (k == i) continue;
				for (int p = 0; p < n; ++p)//run by columns
					if (p != j)
						minor.push_back(matrix[k*n + p]);
			}
			int det = determinate(n - 1, minor);
			matrix[i*n + j] = matrix[i*n + j] * det * pow(-1, i + j);
			cout << "\ni = " << i << ", j = " << j << ":\n";
			for (int k = 0; k < minor.size(); ++k){
					cout << minor[k] << ' ';
			}
			cout <<" det = "<< det;
		}
		cout << '\n';
	}
	cout << "matrix additions':\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i*n + j] << ' ';
		}
		cout << '\n';
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
