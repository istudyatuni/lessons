// quick_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
void sort(vector<int>& a, int n, int left, int right);
int main()
{
	int n = 4;
	vector<int> a;
	for (int i = 0; i < n; ++i) {
		a.push_back(rand() % 100);
		cout << a[i] << ' ';
	}
	cout << "\nmassiv after sorting:\n";
	sort(a, n, 0, n - 1);
	for (int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
	cout << '\n';
	system("pause");
}
void sort(vector<int>& a, int n, int left, int right) {
	if (left == right)
		return;
	int mid = (left + right) / 2;
	for (int i = left; i < mid; ++i) {
		if (a[i] > a[mid]) {
			for (int j = mid; j < right; ++j) {
				if (a[j] < a[mid])
					swap(a[i], a[j]);
			}
		}
	}
	sort(a, n / 2, left, mid - 1);
	sort(a, n / 2, mid, right);
	return;
}
