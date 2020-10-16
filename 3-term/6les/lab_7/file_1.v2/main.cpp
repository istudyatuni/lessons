#include <bits/stdc++.h>
using namespace std;
vector<int> reverse_matrix(int s, vector<int> a);
vector<int> matrix_sum(int s, vector<int>a, vector<int>b);
vector<int> matrix_sub(int s, vector<int>a, vector<int>b);
vector<int> matrix_mul(int s, vector<int>a, vector<int>b);
int main()
{
    ifstream f("file.txt");
    int n, s = 0;
    f >> n;
    vector<int> a;
    cout << "source matrix:\n";
    for (int i = 0; i < n; ++i){
        int tmp;
        for (int j = 0; j < n; ++j){
            if (!f.eof()){
                f >> tmp;
                a.push_back(tmp);
                cout << a[i*n + j] << ' ';
                s++;
            }
        }
        cout << '\n';
    }
    f.close();
    if (s != n*n){
        cout << "size != " << n << '*' << n;
        return 1;
    }
    cout << "matrix b:\n";
    vector<int> b(n*n);
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i%2)
                b[i*n + j] = 2*a[i*n + j];
            else b[i*n + j] = a[i*n + j]*a[i*n + j];
            cout << b[i*n + j] << ' ';
        }
        cout << '\n';
    }
    cout << "transposition a:\n";
    vector<int> c;
    c = matrix_sum(n, a, reverse_matrix(n, b));
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            swap(a[i*n + j], a[j*n + i]); /// transposition
            c[i*n + j] *= 2; /// C *= 2
        }
    }
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << a[i*n + j] << ' ';
        }
        cout << '\n';
    }
    cout << "A *= B :\n";
    a = matrix_mul(n, a, b);
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
	//cout << "det = " << det << '\n';
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
vector<int> matrix_sum(int s, vector<int>a, vector<int>b){
    for (int i = 0; i < s; ++i){
        for (int j = 0; j < s; ++j){
            a[i*s + j] += b[i*s + j];
        }
    }
    return a;
}
vector<int> matrix_sub(int s, vector<int>a, vector<int>b){
    for (int i = 0; i < s; ++i){
        for (int j = 0; j < s; ++j){
            a[i*s + j] -= b[i*s + j];
        }
    }
    return a;
}
vector<int> matrix_mul(int s, vector<int>a, vector<int>b){
    /// A *= B
    vector<int>res(s*s);
    for (int i = 0; i < s; ++i){
        for (int j = 0; j < s; ++j){
            for (int k = 0; k < s; ++k){
                res[i*s + j] += a[i*s + k] * b[i*k*s + j];
            }
            cout << res[i*s + j] << ' ';
        }
        cout << '\n';
    }
    return a;
}
