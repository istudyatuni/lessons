// prog12.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//найти сумму элементов квадратной матрицы, находящихся по периметру и на диагоналях
//если суммы равны, заменить каждый отрицательный элемент на его модуль

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
	ifstream f("input.txt");
	int n;
	f >> n;
	vector<int>x;
	int per_sum = 0, diag_sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int a;
			f >> a;
			x.push_back(a);
			if (i == j || j == n - i - 1)
				diag_sum += a;
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				per_sum += a;
			cout << x[i*n + j] << ' ';
		}
		cout << '\n';
	}
	f.close();
	cout << "perimeter sum = " << per_sum << '\n';
	cout << "diagonal sum = " << diag_sum << '\n';
	if (diag_sum == per_sum) {
		cout << "sum is equal\n";
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j) {
				if (x[i*n + j] < 0)
					x[i*n + j] = 0 - x[i*n + j];
				cout << x[i*n + j] << ' ';
			}
			cout << '\n';
		}
	}
	system("pause");
	return 0;
}
