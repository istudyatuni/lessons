#include <bits/stdc++.h>
using namespace std;
struct ration {
	long m, n; // m / n
};
ration reduct (ration a); //сокращение
ration add_rat (ration a, ration b);
ration sub_rat (ration a, ration b);
ration mul_rat (ration a, ration b);
ration div_rat (ration a, ration b);
ration in_rat ();
void out_rat (ration a);
 
int main() {
	/// m / n ///
	srand(time(0));
	int size;
	cin >> size;
	ration a;
	vector<vector<ration>> matrix (size);
	cout << "matrix:\n";
	vector<int> b;
	for (int i = 0; i < size; ++i){
		b.push_back(rand()%10);
		for (int j = 0; j < size; ++j){
			a.m = rand()%4;
			a.n = rand()%9 + 1;
			matrix[i].push_back(reduct(a));
			out_rat(matrix[i][j]);
		}
		cout << "= " << b[i]<< endl;
	}
	for (int p = 0; p < size-1; ++p){
		// 1 wiki.ru
		int nz = p;//number non-zero column
		int k = 0;//                          k==0
		for (int j = p; j < size && nz == p && !k; ++j){
			for (int i = p; i < size; ++i){
				if (nz == p && matrix[i][j].m != 0){
					nz = j; //search first non-zero column
					k = 1; //if j == p, nz <= 0
					break;
				}
			}
		}
		// 2
		if (matrix[p][nz].m == 0){
			int tmp;
			for (int i = p + 1; i < size; ++i)
				if (matrix[i][nz].m != 0){
					tmp = i;
					break;
				}
			for (int j = p; j < size; ++j){
				swap(matrix[p][j], matrix[tmp][j]);
			}
		}
		// 3
		for (int j = p; j < size; ++j){
			if (j != nz)
				div_rat (matrix[p][j], matrix[p][nz]);
		}
		// 4
		for (int i = p + 1; i < size; ++i){
			ration tmp;
			for (int j = p; j < size; ++j){
				tmp = mul_rat (matrix[p][j], matrix[i][p]);
				matrix[i][j] = sub_rat (matrix[i][j], tmp);
			}
		}
	}
	cout << "up-triangle matrix:\n";
	for (int i = 0; i < size; ++i){
		for (int j = 0; j < size; ++j)
			out_rat(matrix[i][j]);
		cout << endl;
	}
	return 0;
}
ration reduct (ration a){
	int n = min (a.m, a.n);
	for (int i = n; i > 1; --i){
		if (a.m%i == 0 && a.n%i == 0){
			a.m /= i;
			a.n /= i;
			break;
		}
	}
	return a;
}
ration add_rat (ration a, ration b){
	ration res;
	res.m = a.m*b.n + b.m*a.n;
	res.n = a.n*b.n;
	return reduct(res);
}
ration sub_rat (ration a, ration b){
	ration res;
	res.m = a.m*b.n - b.m*a.n;
	res.n = a.n*b.n;
	return reduct(res);
}
ration mul_rat (ration a, ration b){
	ration res;
	res.m = a.m*b.m;
	res.n = a.n*b.n;
	return reduct(res);
}
ration div_rat (ration a, ration b){
	ration res;
	res.m = a.m*b.n;
	res.n = a.n*b.m;
	return reduct(res);
}
ration in_rat (){
	ration a;
	//cout << "enter rational number: ";
	cin >> a.m >> a.n;
	cout << endl;
	return reduct(a);
}
void out_rat (ration a){
	if (a.m == 0)
		cout << a.m << "/0"<< "  ";
	else cout << a.m << "/" << a.n << "  ";
}