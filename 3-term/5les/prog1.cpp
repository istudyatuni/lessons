#include <iostream>
using namespace std;

int main()
{
    int x;
    cout<<"x:";
    cin >> x;
    int chisl=1, znam=1;
    for (int i=2; i<=64; i*=2){
        chisl *= (x - i);
        znam *= (x - (i-1));
    }
    cout << "result = "<<double(chisl)/double(znam);
    return 0;
}
