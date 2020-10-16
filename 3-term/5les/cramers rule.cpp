#include <bits/stdc++.h>
using namespace std;
int calculate_det (vector <int> &a, int i, int s);
float calculate_xi (vector<int> &a, vector<int> &b, int i, int n);
float det;
int main() {
	cout << "enter n: ";
	int n;
	cin >> n;
	vector<int>mat;
	int a;
	for (int i = 0; i < n*n; ++i){
		cin >> a;
		mat.push_back(a);
	}
	vector<int>b;
	cout << "enter vector b: ";
	for (int i = 0; i < n; ++i){
		cin >> a;
		b.push_back(a);
	}
	det = calculate_det(b, 0, n);
	if (det == 0) {
		cout << "det = 0!";
		return 0;
	}
	vector<float>x(n);
	for (int i = 0; i < n; ++i){
		x[i] = calculate_xi(mat, b, i, n);
	}
	return 0;
}
float calculate_xi (vector<int> &a, vector<int> &b, int i, int n){
	vector<int>x(n*n);
	for (int j = 0; j < n*n; ++j){
		if (j%n == i) x[j] = b[j/n];
		else x[j] = a[j];
	}
	float ai = calculate_det (x, 0, n*n);
	return ai/det;
}
int calculate_det (vector <int> &a, int i, int s){//row = 0, i is column
	int k = a[i];//a[0][i]
	int size = s*s;
	if (size == 4){//end recursion
		vector<int> b;
		for (int j = 0; j < size; ++j){
			b.push_back(a[j]);
		}
		return b[0]*b[3]-b[1]*b[2];
	}
	else {
		vector<int> b;
		for (int j = s; j < size; ++j){//copy without 0 row and i column
			if (j%s == i) continue;
			b.push_back(a[j]);
		}
		//b is minor
		int res = 1;
		for (int j = 0; j < s; ++j){
			if (j%2 == 0)
				res -= k*calculate_det(b, i++, s-1);
			else res += k*calculate_det(b, i++, s-1);
		}
		return res;
	}
}
