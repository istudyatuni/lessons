//worked correct
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
double determinant(int size_of_matrix, vector<vector<double> >matrix);
void up_zero(vector<vector<double> > &a, vector<double> &b, int n);
int main() {
	ifstream f("input.txt");
	cout << "enter size: ";
	int size;
	f >> size;
	vector<vector<double> > matrix(size);
	cout << size << "\nmatrix:\n";
	vector<double> b;
	vector<double> x (size);
	// read from file
	for (int i = 0; i < size; ++i) {
		double a;
		for (int j = 0; j < size; ++j) {
			f >> a;
			matrix[i].push_back(a);
			cout << matrix[i][j] << ' ';
		}
		f >> a;
		b.push_back(a);
		cout << "= " << b[i] << '\n';
	}
	f.close();
	double det = determinant(size, matrix);
	cout << "determinate = " << det << '\n';
	cout << "debug\n";
	up_zero(matrix, b, size);
	cout << "up-triangle matrix:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			cout << matrix[i][j] << ' ';
		cout << "= " << b[i] << '\n';
	}
	for(int i = 0; i < size/2; i++)
        swap(b[size - i - 1], b[i]);
    for(int j = 0; j < size; j++)
        for(int i = 0; i < size/2; i++)
            swap(matrix[i][j], matrix[size - i - 1][j]);
    for(int j = 0; j < size; j++)
        for(int i = 0; i < size/2; i++)
            swap(matrix[j][i], matrix[j][size - i - 1]);

	for (int j = size - 1; j >= 0; --j) { // to step view
		for (int i = j - 1; i >= 0; --i) {
			double del = matrix[i][j] / matrix[j][j];
			for (int k = size - 1; k >= j; --k) {
				matrix[i][k] -= matrix[j][k] * del;
			}
			b[i] -= b[i] * del;
		}
	}
	up_zero(matrix, b, size);
	cout << "\nstep view matrix:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			cout << matrix[i][j] << ' ';
		cout << "= " << b[i] << '\n';
	}
	for (int i = 0; i < size; i++)
        x[i] = b[i] / matrix[i][i];
    for(int i = 0; i < size / 2; i++){
        swap(x[i], x[size - i - 1]);
    }
	cout << "\nsolution as matrix x:\n";
	for (int i = 0; i < size; ++i) {
		cout << "x[" << i << "] = " << x[i] << '\n';
	}
	//cout << '\n';
	//system("pause");
	return 0;
}
double determinant(int size_of_matrix, vector<vector<double> >matrix) {
	if (size_of_matrix < 1) {
		cout << "size matrix isn't correct!\n";
		return 0;
	}
	if (size_of_matrix == 1) return matrix[0][0];
	if (size_of_matrix == 2) return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	int res = 0;
	for (int i = 0; i < size_of_matrix; ++i) {
		vector<vector<double> > b(size_of_matrix - 1);
		int p = 0;
		for (int j = 1; j < size_of_matrix; ++j) {
			for (int k = 0; k < size_of_matrix; ++k)
				if (k != i)
					b[p].push_back(matrix[j][k]);
			p++;
		}
		res += matrix[0][i] * determinant(size_of_matrix - 1, b)*pow(-1, i);
	}
	return res;
}
void up_zero(vector<vector<double> > &matrix, vector<double> &b, int size){
	for (int j = 0; j < size - 1; ++j) { //to up-triangle
		double first = matrix[j][j];
		if (first == 0) {
			for (int i = j + 1; i < size; ++i){
				if (matrix[i][j] != 0){
					swap(matrix[i], matrix[j]);
					swap(b[i], b[j]);
					first = matrix[j][j];
					break;
				}
			}
			cout << "\none of diagonal element is equal 0:\n";
			/// output changed matrix
			for (int i = 0; i < size; ++i){
				for (int k = 0; k < size; ++k){
					cout << matrix[i][k] << ' ';
				}
				cout << '\n';
			}
		}
		for (int i = j + 1; i < size; ++i) {
			double del = matrix[i][j] / matrix[j][j];
			for (int k = j; k < size; ++k) {
				matrix[i][k] -= matrix[j][k] * del;
			}
			b[i] -= b[j] * del;
		}
		cout << "j = " << j << ":\n";
		for (int i = 0; i < size; ++i) {
			for (int k = 0; k < size; ++k)
				cout << matrix[i][k] << ' ';
			cout << "= " << b[i] << '\n';
		}
		cout << '\n';
	}
}