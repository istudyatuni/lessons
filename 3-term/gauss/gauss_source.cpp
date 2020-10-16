#include <iostream>
using namespace std;
void gauss(double **a, double *b, int n)
{
    double d, s;
    for (int k = 0; k < n; k++) // прямой ход
    {
        for (int j = k + 1; j < n; j++)
        {
            d = a[j][k] / a[k][k]; // формула (1)
            for (int i = k; i < n; i++)
                a[j][i] = a[j][i] - d * a[k][i]; // формула (2)
            b[j] = b[j] - d * b[k]; // формула (3)
        }
    }
}
int main()
{
    int n;
    double d, s;
    cout << "enter numbers of unknowns in system lines equations: ";
    cin >> n;
    double **a = new double *[n];//matrix
    for (int i = 0; i < n; i++)
        a[i] = new double [n];
    double *b = new double [n];//free elements
    double *x = new double [n];//solve
    for (int i = 0; i < n; i++)    {
        for (int j = 0; j < n; j++)
        {
            cout << "enter coefficient about " << j <<  " variable " << i << " line: ";
            cin >> a[i][j];
        }
        cout << "enter free element " << i << " line: ";
        cin >> b[i];
    }
    gauss(a, b, n);
    for(int i = 0; i < n/2; i++)
    {
        s = b[i];
        b[i] = b[n-1-i];
        b[n-1-i] = s;
    }
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n/2; i++)
        {
            s = a[i][j];
            a[i][j] = a[n-1-i][j];
            a[n-1-i][j] = s;
        }
    for(int j = 0; j < n; j++)
        for(int i = 0; i < n/2; i++)
        {
            s = a[j][i];
            a[j][i] = a[j][n-1-i];
            a[j][n-1-i] = s;
        }
    gauss(a, b, n);
    for (int j = 0; j < n; j++) x[j] = b[j]/a[j][j];
    for(int i = 0; i < n/2; i++)
    {
        s = x[i];
        x[i] = x[n-1-i];
        x[n-1-i] = s;
    }
    cout << "system roots:" << endl;
    for(int i = 0; i < n; i++)
        cout << "x" << i+1 << " = " << x[i] << endl ;
    for (int i = 0; i < n; i++) delete[] a[i];
    delete[] a;
    delete[] b;
    delete[] x;
    return 0;
}