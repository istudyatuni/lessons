#include <iostream>
using namespace std;
void gauss(double **a, double *b, int n){
    double d;
    for (int k = 0; k < n; k++) // прямой ход
    {
        for (int j = k + 1; j < n; j++)
        {
            d = a[j][k] / a[k][k]; // формула (1)
            for (int i = k; i < n; i++)
                a[j][i] -= d * a[k][i]; // формула (2)
            b[j] -= d * b[k]; // формула (3)
        }
    }
}
void print(double **a, double *b, int n){
    cout << "print\n";
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout << a[i][j] << ' ';
        }
        cout << "= " << b[i] << '\n';
    }
}
int main(){
    int n;
    cout << "enter numbers of unknowns in system lines equations: ";
    cin >> n;
    double **a = new double *[n];//matrix
    for (int i = 0; i < n; i++)
        a[i] = new double [n];
    double *b = new double [n];//free elements
    double *x = new double [n];//solve
    for (int i = 0; i < n; i++){
        cout << i << " line: ";
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
        cout << "free element " << i << " line: ";
        cin >> b[i];
    }
    gauss(a, b, n);
    print(a, b, n);
    for(int i = 0; i < n/2; i++)
        swap(b[n - i - 1], b[i]);
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n/2; i++)
            swap(a[i][j], a[n - i - 1][j]);
    print(a, b, n);
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n/2; i++)
            swap(a[j][i], a[j][n - i - 1]);
    print(a, b, n);
    gauss(a, b, n);
    print(a, b, n);
    for (int i = 0; i < n; i++)
        x[i] = b[i] / a[i][i];
    print(a, b, n);
    for(int i = 0; i < n / 2; i++){
        swap(x[i], x[n - i - 1]);
    }
    print(a, b, n);
    cout << "system roots:" << endl;
    for(int i = 0; i < n; i++)
        cout << "x" << i << " = " << x[i] << endl ;
    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
    delete[] b;
    delete[] x;
    return 0;
}