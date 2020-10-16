#include <bits/stdc++.h>
using namespace std;
class Ration {
    long m, n;
public:
    Ration(long a = 0, long b = 1){
        m = a;
        n = b;
    }
    Ration make(long a, long b = 1){
        m = a;
        n = b;
    }
    Ration reduct (){
        for (int i = min (m, n); i > 1; --i)
            if (m%i == 0 && n%i == 0){
                m /= i;
                n /= i;
                break;
            }
    }
    Ration add (Ration b){
        m = m*b.n + b.m*n;
        n = n*b.n;
        reduct();
    }
    Ration sub (Ration b){
        m = m*b.n - b.m*n;
        n = n*b.n;
        reduct();
    }
    Ration mul (Ration b){
        m = m*b.m;
        n = n*b.n;
        reduct();
    }
    Ration div(Ration b){
        m = m*b.n;
        n = n*b.m;
        reduct();
    }
    void print(){
        if (m == 0)
            cout << m << "/0"<< "  ";
        else cout << m << "/" << n << "  ";
    }
    Ration input(){
        cout << "enter rational number: ";
        cin >> m >> n;
        reduct();
    }
};
int main()
{
    Ration a(7, 8);
    Ration b(8, 16);
    a.add(b);
    a.print();
    return 0;
}
