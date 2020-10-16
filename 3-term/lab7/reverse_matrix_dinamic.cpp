// reverse_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int determinate (int n, float** a);
float** reverse_matrix(int s, float** a);
int main()
{
	ifstream f("input2.txt");
	int n;
	f >> n;
	float **a = new float* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new float[n];
		for (int j = 0; j < n; ++j) {
			int v;
			f >> v;
			a[i][j] = v;
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	f.close();
	if (determinate(n, a) == 0){
        cerr << "determinate = 0!\n";
        cin.get();
        return 0;
	}
	a = reverse_matrix(n, a);
	cout << "reverse matrix:\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
int determinate(int n, float** a){
	if (n == 2) {//end recursion
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	int res = 0;
	for (int i = 0; i < n; ++i) {//search det
		float** b = new float* [n - 1]; //minor
		for (int j = 0; j < n - 1; ++j)
			b[j] = new float[n - 1];
		//decomposition without 0 row and i column
		for (int j = 0; j < n - 1; ++j) {//write minor to b, j is row
			for(int k = 0; k < i; ++k)//run by columns
				b[j][k] = a[j + 1][k];
			for(int k = i; k < n - 1; ++k){
				b[j][k] = a[j + 1][k + 1];
			}
		}
		res += a[0][i] * determinate(n - 1, b) * pow(-1, i);
	}
	return res;
}
float** reverse_matrix(int s, float** a){
	int det = determinate(s, a);
	cout << "det = " << det << '\n';
	float** matrix_add = new float*[s];
	for (int i = 0; i < s; ++i)
		matrix_add[i] = new float[s];
	for (int i = 0; i < s; ++i) {
		for (int j = 0; j < s; ++j) {
			float** minor = new float*[s - 1];
			for (int k = 0; k < s - 1; ++k)
				minor[k] = new float[s - 1];
			for(int k = 0; k < i; ++k){// write minor, k is row
				for(int p = 0; p < j; ++p)
					minor[k][p] = a[k][p];
				for(int p = j; p < s - 1; ++p)
					minor[k][p] = a[k][p + 1];
			}
			for(int k = i; k < s - 1; ++k){
				for(int p = 0; p < j; ++p)
					minor[k][p] = a[k + 1][p];
				for(int p = j; p < s - 1; ++p)
					minor[k][p] = a[k + 1][p + 1];
			}
			int det_min = determinate(s - 1, minor);
			matrix_add[i][j] += det_min * pow(-1, i + j) / det;
		}
	}
	for (int i = 0; i < s; ++i)
		for (int j = i; j < s; ++j)
			swap(matrix_add[i][j], matrix_add[j][i]);
	return matrix_add;
}