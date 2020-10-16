// number 1
#include <bits/stdc++.h>
using namespace std;
int simple (int a){
    for (int i = 2; i < sqrt(a); ++i){
        if (a%i == 0)
            return 0;
    }
    if (a == 4) return 0;
    return 1;
}
int main()
{
    ifstream f("file.txt", ios::in);
    int n, s = 0;
    f >> n;
    vector<vector<int>> matrix (n);
    cout << "source matrix:\n";
    for (int i = 0; i < n; ++i){
        int a;
        for (int j = 0; j < n; ++j){
            if (!f.eof()){
                f >> a;
                matrix[i].push_back(a);
                cout << matrix[i][j] << ' ';
                s++;
            }
        }
        cout << '\n';
    }
    if (s != n*n){
        cout << "size != " << n << '*' << n;
        return 1;
    }
    s = 0;//number simple
    int sum = 0;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            if (i != j && simple(matrix[i][j])){
                s++;
                sum += matrix[i][j];
            }
        }
    }
    cout << "numbers simple(with 0): " << s << "\nsum = " << sum << '\n';
    ofstream res("res.txt");
    if (!s){
        for (int i = 0; i < n; ++i){
            swap(matrix[i][i], matrix[i][n - i - 1]);
            for (int j = 0; j < n; ++j){
                res << matrix[i][j] << ' ';
            }
            res << '\n';
        }
    }
    res.close();
    f.close();
    return 0;
}
