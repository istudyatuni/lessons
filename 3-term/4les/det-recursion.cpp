#include <bits/stdc++.h>
using namespace std;
int calculate (vector <int> &a, int i, int size);
int main() {
	cout<<"enter n:";
	int n;
	cin >> n;
	vector <int> det (n*n);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> det[i*n + j];
		}
	}
	int res = calculate (det, 0, n*n);
	cout << "determinate = " << res;
	return 0;
}
int calculate (vector <int> &a, int i, int size){//row = 0, i is column
	int k = a[i];//a[0][i]
	int s = sqrt(size);//s = n
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
		int res = 0;
		for (int j = 0; j < s; ++j){
			if (j%2 == 0)
				res -= k*calculate(b, i++, (s-1)*(s-1));
			else res += k*calculate(b, i++, (s-1)*(s-1));
		}
		return res;
	}
}