#include <vector>
#include "quad.h"

class Parallelogram: public Quadrangle {
    int isExist() {
        return (length(0, 1) == length(2, 3) && length(1, 2) == length(3, 0));
    }
public:
    Parallelogram();
    Parallelogram(int a): Quadrangle(a){
    }
    Parallelogram(double x1, double x2, double x3, double x4,
                   double y1, double y2, double y3, double y4):
                    Quadrangle(x1, x2, x3, x4, y1, y2, y3, y4) {
        if (!isExist()) {
            cout << "parallelogram with these coordinates does not exist\n";
            input();
        }
    }
};

int main() {
    cout << "enter n and m: ";
    int n, m;
    cin >> n >> m;
    vector<Quadrangle> squad;
    squad.reserve(n);
    cout << "enter quadrangles:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << ": ";
        Quadrangle t(5);
        squad.push_back(t);
    }
    vector<Parallelogram> para;
    para.reserve(m);
    cout << "enter parallelograms:\n";
    for (int i = 0; i < m; ++i) {
        cout << i << ": ";
        Parallelogram tm(5);
        para.push_back(tm);
    }
    double s = 0;
    int mini = 0, maxi = 0;
    cout << "quadrangle's areas:\n";
    for (int i = 0; i < n; ++i) {
        cout << i << "'s area = " << squad[i].area() << '\n';
        s += squad[i].area();
    }
    s /= n;
    cout << "average area = " << s << '\n';
    double mx = para[0].area(), mn = para[0].area(), tmp;
    for (int i = 1; i < m; ++i) {
        tmp = para[i].area();
        if (tmp > mx) {
            mx = tmp;
            maxi = i;
        }
        if (tmp < mn) {
            mn = tmp;
            mini = i;
        }
    }
    cout << "\nmin parallelogram's area = " << mn << ", i = " << mini;
    cout << "\nmax area = " << mx << ", i = " << maxi;
    return 0;
}