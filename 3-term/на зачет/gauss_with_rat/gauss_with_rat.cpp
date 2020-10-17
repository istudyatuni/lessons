//worked
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
using namespace std;
struct ration {
	long long m, n; // m / n
};
ration reduct(ration a); //сокращение
ration add_rat(ration a, ration b);
ration sub_rat(ration a, ration b);
ration mul_rat(ration a, ration b);
ration div_rat(ration a, ration b);
void out_rat(ration a);
template <class Type>
Type min(Type a, Type b) {
	return (a < b) ? a : b;
}
int main() {
	/// m / n ///
	ifstream f("input.txt");
	cout << "enter size: ";
	int size;
	f >> size;
	vector<vector<ration>> matrix(size);
	cout <<size<< "\nmatrix:\n";
	vector<ration> b;
	srand(time(0));
	// read from file
	for (int i = 0; i < size; ++i) {
		ration a;
		for (int j = 0; j < size; ++j) {
			f >> a.m;
			//f >> a.n;
			a.n = 1;
			matrix[i].push_back(reduct(a));
			out_rat(matrix[i][j]);
		}
		f >> a.m;
		a.n = 1;
		b.push_back(a);
		cout << "= ";
		out_rat(b[i]);
		cout << '\n';
	}
	cout << "debug\n";
	for (int j = 0; j < size - 1; ++j) { //to up-triangle
		// diagonal elements must even 1
		ration first = matrix[j][j];
		for (int i = 0; i < size; ++i) {
			matrix[j][i] = div_rat(matrix[j][i], first);
		}
		b[j] = div_rat(b[j], first);
		for (int i = j + 1; i < size; ++i) {
			ration del = div_rat(matrix[i][j], matrix[j][j]);
			for (int k = j; k < size; ++k) {
				matrix[i][k] = sub_rat(matrix[i][k], mul_rat(matrix[j][k], del));
			}
			b[i] = sub_rat(b[i], mul_rat(b[i], del));
		}
		if (j == size - 2) {
			//last diagonal element to 1
			first = matrix[size - 1][size - 1];
			matrix[size - 1][size - 1] = div_rat(matrix[size - 1][size - 1], first);
			b[size - 1] = div_rat(b[size - 1], first);
		}
		cout << "j = " << j << ":\n";
		for (int i = 0; i < size; ++i) {
			for (int k = 0; k < size; ++k)
				out_rat(matrix[i][k]);
			cout << "= ";
			out_rat(b[i]);
			cout << '\n';
		}
		cout << '\n';
	}
	cout << "---\nup-triangle matrix:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			out_rat(matrix[i][j]);
		cout << "= ";
		out_rat(b[i]);
		cout << '\n';
	}
	for (int j = size - 1; j >= 0; --j) { // to step view
		for (int i = j - 1; i >= 0; --i) {
			//del = matrix[i][j] / matrix[j][j];
			ration del = div_rat(matrix[i][j], matrix[j][j]);
			for (int k = size - 1; k >= j; --k) {
				//matrix[i][k] -= matrix[j][k] * del;
				matrix[i][k] = sub_rat(matrix[i][k], mul_rat(matrix[j][k], del));
			}
			//b[i] -= b[j] * del;
			b[i] = sub_rat(b[i], mul_rat(b[j], del));
		}
	}
	cout << "step view matrix:\n";
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			out_rat(matrix[i][j]);
		cout << "= ";
		out_rat(b[i]);
		cout << '\n';
	}
	cout << "solution as matrix x:\n";
	for (int i = 0; i < size; ++i) {
		out_rat(b[i]);
	}
	cout << '\n';
	system("pause");
	f.close();
	return 0;
}
ration reduct(ration a) {
	if (a.m > 0 && a.n < 0) {
		//if a / -b , ration = -a / b
		a.m = 0 - a.m;
		a.n = 0 - a.n;
	}
	if (a.m < 0 && a.n < 0) {
		//if -a / -b , ration = a / b
		a.m = 0 - a.m;
		a.n = 0 - a.n;
	}
	int k = 1;
	if (a.m < 0) {
		//for reduct without minus
		k = -1;
		a.m = 0 - a.m;
	}
	int n = min(a.m, a.n);
	for (int i = n; i > 1; --i) {
		if (a.m%i == 0 && a.n%i == 0) {
			a.m /= i;
			a.n /= i;
			break;
		}
	}
	if (k == -1)
		a.m = 0 - a.m;
	return a;
}
ration add_rat(ration a, ration b) {
	ration res;
	res.m = a.m*b.n + b.m*a.n;
	res.n = a.n*b.n;
	return reduct(res);
}
ration sub_rat(ration a, ration b) {
	ration res;
	res.m = a.m*b.n - b.m*a.n;
	res.n = a.n*b.n;
	return reduct(res);
}
ration mul_rat(ration a, ration b) {
	ration res;
	res.m = a.m*b.m;
	res.n = a.n*b.n;
	return reduct(res);
}
ration div_rat(ration a, ration b) {
	ration res;
	res.m = a.m*b.n;
	res.n = a.n*b.m;
	return reduct(res);
}
void out_rat(ration a) {
	if (a.n == 1 || a.m == 0)
		cout << a.m << "   ";
	else cout << a.m << "/" << a.n << "  ";
}
/*  1-st search solution x
vector<ration> x(size);
	for (int j = size - 1; j >= 0; --j) {
		for (int k = size - 1; k > j; --k) {
			b[j] = sub_rat(b[j], matrix[k][j]);
		}
		b[j] = div_rat(b[j], matrix[j][j]);
		x[j] = add_rat(x[j], b[j]);
	}
*/
