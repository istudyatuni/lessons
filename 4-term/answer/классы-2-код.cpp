#include <iostream>
using namespace std;

class myClass {
    int a;
public:
    myClass(){
        a = 0;
    }
    void set(int i){
        a = i;
    }
    myClass& operator+(int i){
        a += i;
        return *this;
    }
    myClass operator++(int){
        a++;
        return *this;
    }
    void print(){
        cout << a;
    }
    ~myClass(){};
};
int main() {
    myClass a;
    a = a + 5;
    a.print();
    a++;
    a.print();
    return 0;
}