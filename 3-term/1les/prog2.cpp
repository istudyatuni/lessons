#include <iostream>

using namespace std;

int main()
{
    int n, a;
    cout << "enter n,a:";
    cin>>n>>a;
    float pr=1,res=0;
    for(int i=0;i<=n;i++){
        pr*=a+i;
        res+=1/pr;
    }
    cout<<"result="<<res;
    return 0;
}
