#include <bits/stdc++.h>
using namespace std;
class Vector{
    int n;
    int* mas;
public:
    Vector(){
        n = 0;
    }
    make(int sz){
        n = sz;
        mas = new int [n];
        for (int i = 0; i < n; ++i){
            cout << i << ": ";
            cin >> mas[i];
        }
    }
    void print(){
        for (int i = 0; i < n; ++i){
            cout << mas[i] << ' ';
        }
        cout << endl;
    }
};
class matrix{
    int m, n;
    int** mas;
};
int main()
{
    Vector a;
    a.make(5);
    a.print();
    return 0;
}
