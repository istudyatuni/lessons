//choosing
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "enter n: ";
    cin>>n;
    int *mas = new int[n];
    for (int i=0; i<n; i++){
        cout << i <<" = ";
        cin >> mas[i];
    }
    for (int i=n-1; i>=0; i--){
        int mx = mas[i];
        int imax = i;
        for (int j = i-1; j>=0; j--)
            if (mas[j] > mx){
                mx = mas[j];
                imax = j;
            }
        int tmp = mas[i];
        mas[i] = mas[imax];
        mas[imax] = tmp;
    }
    for (int i=0; i<n; i++)
        cout << mas[i] << ' ';
    delete mas;
    return 0;
}
