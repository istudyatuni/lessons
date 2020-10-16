#include <iostream>
#include <cmath>
using namespace std;
float mod(float a){
    if (a < 0)
        a = - a;
    return a;
}
int main()
{
    float eps, frac = 1, fct = 1;
    cout << "enter eps less than 1: ";
    cin >> eps;
    if (eps >= 1){ ///eps < 1
        cout << "WHAT? You're wrong";
        return 1;
    }
    double sum = 1; //because 1st fraction equal 1
    double i = 1; //start from 2nd iteration
    while (mod(frac) >= eps){
        frac = pow(-2.0, i) / fct;
        sum += frac;
        cout<<i<<' '<<frac<<' '<<sum<<endl;
        i++;
        fct *= i;
    }
    cout <<"sum = " << sum;
    return 0;
}
