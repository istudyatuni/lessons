#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
float** mul_matrix (float** a, float** b, int n);
float determinate (int n, float** a);
float** reverse_matrix(int s, float** a);
int main(){
	ifstream f("input.txt");
	int n; // size
	f >> n;
	float *c = new float[n];
	float **a = new float* [n];
	cout << "source matrix: ";
	for (int i = 0; i < n; ++i){
		a[i] = new float[n];
		f >> c[i];
		cout << c[i] << ' ';
	}
	f.close();
	cout << "\nmatrix a:\n";
	float max_a;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			 /// формируем матрицу а:
			a[i][j] = c[i] * c[j];
			if (i == 0 && j == 0)
		/// записываем в max нулевой элемент
				max_a = a[i][j];
			else if (a[i][j] > max_a)
		/// в остальных случаях проверяем, больше ли текущий элемент чем max
				max_a = a[i][j];
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "determinate a = " << determinate(n, a) << '\n';
	cout << "max element = " << max_a;
	float **b = new float* [n];
	cout << "\nmatrix b:\n";
	for (int i = 0; i < n; ++i){
		b[i] = new float[n];
		for (int j = 0; j < n; ++j){
			b[i][j] = a[i][j] / max_a;
			cout << b[i][j] << ' ';
			b[i][j] *= 3;
			if (i == j){
				b[i][j] -= 1;
				a[i][j] += 4;
			}
		}
		cout << '\n';
	}
	cout << "changed matrix a:\n";
	for (int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	/// here we get X * A = B
	float det = determinate(n, a);
	float** rev;
	if (det != 0){
		rev = reverse_matrix(n, a);
		b = mul_matrix(b, rev, n);
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << b[i][j] << ' ';
		}
		cout << '\n';
	}
	for (int i = 0; i < n; ++i){
		delete []a[i];
		delete []b[i];
	}
	delete[]a;
	delete[]b;
	delete[]c;
	return 0;
}
float** mul_matrix(float** a, float** b, int n){
	float** res = new float*[n];
	for (int i = 0; i < n; ++i){
		res[i] = new float[n];
		for (int j = 0; j < n; ++j){
			res[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			for(int k = 0; k < n; ++k){
				res[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return res;
}
float determinate(int n, float** a){
	if (n == 2) {//end recursion
		return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	}
	float res = 0;
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
	float det = determinate(s, a);
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
			float det_min = determinate(s - 1, minor);
			matrix_add[i][j] = det_min * pow(-1, i + j) / det;
		}
	}
	for (int i = 0; i < s; ++i)
		for (int j = i; j < s; ++j)
			swap(matrix_add[i][j], matrix_add[j][i]);
	return matrix_add;
}