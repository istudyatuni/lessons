//П(i=2 to 10)=(1 - 1/fct) * (1 - 1/fct(i))//произведение по i от 2 до 10
#include <iostream>
using namespace std;

int main()
{
    float fct=2;
    double pr=1;
    for (int i=2; i<=10; i++){
        pr *= (1 - 1/fct) * (1 - 1/fct);
        //cout<<fct<<' '<<(1-1/fct)<<' '<<(1 - 1/fct) * (1 - 1/fct)<<"   "<<pr<<endl;
        fct *= (i+1);
    }
    cout << "result = "<<pr;
    return 0;
}
