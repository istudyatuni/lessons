#include <bits/stdc++.h>
using namespace std;
//#define pb push_back
struct circle {
    int x, y;
    int rad;
};
circle input (){
    circle res;
    cout << "x, y: ";
    cin >> res.x >> res.y;
    cout << "rad: ";
    cin >> res.rad;
    return res;
}
float dis (circle a){
    float gip = (sqrt(a.x * a.x + a.y * a.y));
    return fabs(gip - a.rad);
}
void out (circle a){
    cout << '(' << a.x << ',' << a.y << "), r = " << a.rad << "; dis = " << dis(a) << endl;
}
int main()
{
    vector<circle>mas;
    cout << "how many circles? ";
    int a;
    cin >> a;
    for (int i = 0; i < a; ++i){
        mas.push_back(input());
    }
    float mx = dis(mas[0]);
    int k = 0;
    for (int i = 1; i<a; ++i){
        if (dis(mas[i]) > mx){
            mx = dis(mas[i]);
            k = i;
        }
    }
    for (int i = 0; i < a; ++i)
        out(mas[i]);
    cout << "\nmaximum distance:\n";
    out(mas[k]);
    return 0;
}
