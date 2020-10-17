// reverse_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
int determinate(int s, vector <int> a);
vector<int> reverse_matrix(int s, vector<int>a);
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
	if (determinate(n, matrix) == 0){
        cerr << "determinate = 0!\n";
        cin.get();
        return 0;
	}
	matrix = reverse_matrix(n, matrix);
	cout << "reverse matrix:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i*n + j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
int determinate(int s, vector <int> a) {
    if (s < 1){
        cout << "size determinate not correct!\n";
        return 0;
    }
    if (s == 1) return a[0];
	if (s == 2) {//end recursion
		return a[0] * a[3] - a[1] * a[2];
	}
	int res = 0;
	for (int i = 0; i < s; ++i) {//search det
		vector<int> b; //minor
		///decomposition without 0 row and i column
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
vector<int> reverse_matrix(int s, vector<int>a){
	int det = determinate(s, a);
	cout << "det = " << det << '\n';
	vector<int>matrix_add(s*s);
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			vector<int>minor;
			for (int k = 0; k < s; ++k) {//write minor, k is row
				if (k == i) continue;
				for (int p = 0; p < s; ++p)//run by columns
					if (p != j)
						minor.push_back(a[k*s + p]);
			}
			int det_min = determinate(s - 1, minor);
			matrix_add[i*s + j] = det_min * pow(-1, i + j) / det;
		}
	}
	for (int i = 0; i < s; ++i){
        for (int j = i; j < s; ++j){
            swap(matrix_add[i*s + j], matrix_add[j*s + i]);
        }
    }
    return matrix_add;
}
