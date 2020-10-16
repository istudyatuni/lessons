#include <bits/stdc++.h>
using namespace std;
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
    for (int i = 0; i < n; ++i){
        for (int j = i; j < n; ++j){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    ofstream res("res.txt");
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            res << matrix[i][j] << ' ';
        }
        res << '\n';
    }
    cout << "row up: ";
    for (int i = 0; i < n; ++i){
        int k = 1;
        for (int j = 1; j < n; ++j){
            if (matrix[i][j] <= matrix[i][j - 1])
                k = 0;
        }
        if (k)
            cout << i + 1 << ' ';
    }
    cout << "\nresult matrix:\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    res.close();
    f.close();
    return 0;
}
