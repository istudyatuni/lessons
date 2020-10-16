#include <iostream>

using namespace std;

int main()
{
    int a, b, n;
    cout << "a1=";
    cin>>a;
    cout<<"b1=";
    cin>>b;
    cout<<"n=";
    cin>>n;
    //float sum=(a+b)/2; //first summand
    float sum=0;
    int ak=a; //temp value for a
    float fct=1;
    for(int k=1; k<=n; k++){
        fct*=k+1;//знаменатель
        sum+=ak*b/fct;
        ak=2*b+a;
        b=2*a*a+b;
        a=ak;
    }
    cout<<"sum="<<sum;
    return 0;
}
