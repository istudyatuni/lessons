// jordan_gauss_without_rat.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//it is determinate without recursion

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	ifstream f("input.txt");
	cout << "enter size: ";
	int size;
	f >> size;
	cout << size << '\n';
	vector<vector<double>> matrix(size);
	cout << "matrix:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			double a;
			f >> a;
			matrix[i].push_back(a);
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int j = 0; j < size - 1; ++j) {
		for (int i = j + 1; i < size; ++i) {
			double del = matrix[i][j] / matrix[j][j];
			for (int k = j; k < size; ++k) {
				matrix[i][k] -= matrix[j][k] * del;
			}
		}
	}
	cout << "up-triangle:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << matrix[i][j] << ' ';
		}
		cout << '\n';
	}
	double det = 1;
	for (int i = 0; i < size; ++i) {
		det *= matrix[i][i];
	}
	cout << "determinate = " << det << '\n';
	system("pause");
	f.close();
	return 0;
}
