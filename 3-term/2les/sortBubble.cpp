//bubble
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int n;
    cout << "enter n: ";
    cin>>n;
    int *mas = new int[n];
    for (int i=0; i<n; i++){
        //cout << i <<" = ";
        //cin >> mas[i];
        mas[i]=rand()%10;
        cout<<mas[i]<<' ';
    }
    cout<<endl;
    for (int i=0;i<n;i++){
        for (int j=0; j<n - i; j++){
            if (mas[j] > mas[j+1])
                swap(mas[j], mas[j+1]);
        }
    }
    for (int i=0; i<n; i++)
        cout << mas[i] << ' ';
    delete mas;
    return 0;
}
