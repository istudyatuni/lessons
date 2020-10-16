#include <iostream>
#include <cmath>
#include <ctime>
#define PI 3.14159265
using namespace std;
double ctg(double deg){
    return sin(deg) / cos(deg);
}
int check = 0;
class trapeze{
    //top base is smaller than bottom base
    //a > 0 and 0 < degrees <= 90!
    double a, b, alpha, beta;//bases, angles
public:
    static int count; //counter for number objects
    static void inc_count(){
        count++;
    }
    static void dec_count(){
        count--;
    }
    trapeze(int x = 0, int y = 0, int al = 0, int bet = 0){
        int fool = 0;
        a = x;
        b = y;
        alpha = al;
        beta = bet;
        while (a < 0 && !check){
            cout << "a = " << a << " isn't correct! enter again: ";
            cin >> a;
            fool++;
            if (fool == 10){
                check = 1;
                goto f;
            }
        }
        fool = 0;
        while (b < 0 && !check){
            cout << "b = " << b << " isn't correct! enter again: ";
            cin >> b;
            fool++;
            if (fool == 10){
                check = 1;
                goto f;
            }
        }
        fool = 0;
        while ((alpha > 90 || alpha < 0) && !check){
            cout << "alpha = " << alpha << " isn't correct! enter again: ";
            cin >> alpha;
            fool++;
            if (fool == 10){
                check = 1;
                goto f;
            }
        }
        fool = 0;
        while ((beta > 90 || beta < 0) && !check){
            cout << "beta = " << beta << " isn't correct! enter again: ";
            cin >> beta;
            fool++;
            if (fool == 10){
                check = 1;
                goto f;
            }
        }
    f:
        if (check){
            cout << "YOU'RE DUMB FOOL! SHUT UP AND GO OFF!\n";
            system("pause");
            exit(0);
        }
        inc_count();
    }
    trapeze(const trapeze& x){
        a = x.a;
        b = x.b;
        alpha = x.alpha;
        beta = x.beta;
        inc_count();
    }
    double area_equal_deg(){
        if (alpha == 90){
            cout << "wtf ";
            return -1;
        }
        return (a - b) / cos(alpha * PI / 180) + a + b;
    }
    double area(){
        if(alpha == beta)
            return area_equal_deg();
        double h = (a - b) / (ctg(alpha) - ctg(beta));
        double c = h / sin(alpha);
        double d = h / sin(beta);
        return a + b + c + d;
    }
    friend ostream& operator<<(ostream& os, trapeze x);
    ~trapeze(){
        dec_count();
    }
};
ostream& operator<<(ostream& os, trapeze x){
    cout << "a = " << x.a << ", b = " << x.b;
    cout << "; alpha = " << x.alpha << "deg, beta = " << x.beta << "deg";
    return os;
}
int trapeze::count = 0;
int is_count(){
    return trapeze::count;
}
int main(){
    cout << "a > 0 and 0 < degrees <= 90!\n\n";
    trapeze a(6, -6, 90, 90);
    cout << a << endl;
    cout << "perimeter = " << a.area() << endl;
    cout << "count number = " << is_count() << endl;
    return 0;
}
