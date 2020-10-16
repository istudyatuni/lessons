#include <bits/stdc++.h>
using namespace std;
int calculate (vector <int> &a, int i, int sz);
int minor (vector <int> &a, int i, int sz);
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
int calculate (vector <int> &a, int i, int sz){//row = 0, i is column
	int k = a[i];//a[0][i]
	int s = sqrt(sz);//s = n
	if (sz == 4){//end recursion
		vector<int> b;
		for (int j = 0; j < sz; ++j){
			b.push_back(a[j]);
		}
		return b[0]*b[3]-b[1]*b[2];
	}
	else {
		vector<int> b;
		for (int j = s; j < sz; ++j){//copy without 0 row and i column
			if (j%s == i) continue;
			b.push_back(a[j]);
		}
		//b is minor
		int res = 0;
            for (int j = 0; j < s; ++j){//search columns
                if (j%2 == 0)//i+j is even
                    res += k*minor(b, i++, (s-1)*(s-1));
                else res -= k*minor(b, i++, (s-1)*(s-1));
            }
		return res;
	}
}
int minor (vector <int> &a, int i, int sz){
    int res=0;
    int s = sqrt(sz);
    for (int f = 0; f < s; ++f)
        res += calculate(a, f, (s-1)*(s-1));
    return res;
}
/*#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int n, fct = 1;
    cout<<"enter n: ";
    cin>>n;
    int *pere = new int[n];
    double** a = new double* [n];
    /// input ///
    for (int i=0; i<n; i++){
        a[i] = new double [n];
        pere[i]=i+1;
        fct *= i+1;
        for (int j=0; j<n; j++){
            a[i][j] = rand()%10;
            cout << a[i][j]<<' ';
        }
        cout << endl;
    }

    for (int p = 0; p < fct; p++){

    }

    for (int i=0;i<n;i++)
        delete[]a[i];
    delete a;
    delete pere;
    return 0;
}*/
