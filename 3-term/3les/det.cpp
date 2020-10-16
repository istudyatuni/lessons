#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));
    int n;
    cout<<"enter n: ";
    cin>>n;
    double** a = new double* [n];
    for (int i=0; i<n; i++){
        a[i] = new double [n+1];
        for (int j=0; j<n; j++){
            a[i][j] = rand()%10;
            cout << a[i][j]<<' ';
        }
        cout << endl;
    }
    cout<<endl;
    for (int k=1;k<n;k++){ //to right
        double x;
        for (int i = k; i<n; i++){ //to down
            x = a[i][k-1] / a[k-1][k-1];
            for (int j=0;j<n+1; j++){ // -
                a[i][j] -= x * a[k-1][j];
                //cout<<k<<' '<<i<<' '<<j<<endl;
            }
        }
    }
    double det=1;
    for (int i=0; i<n; i++){
        det*=a[i][i];
        for (int j=0; j<n; j++)
            cout << a[i][j]<<' ';
        cout << endl;
        delete[] a[i];
    }
    delete[] a;
    cout<<"det = "<<det;
    return 0;
}
