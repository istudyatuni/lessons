#include <iostream>
#include <cmath>
#include <vector>
using std::cout;
using std::cin;
struct point {
    double x;
    double y;
};

class Quadrangle {
protected:
    point coordinates[4];
public:
    Quadrangle(){}
    Quadrangle(point c1, point c2, point c3, point c4) : coordinates{ c1, c2, c3, c4 } {};
    Quadrangle(int i) {
        input();
        if (chek_exists())
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    void input() {
        for (auto& mmbr : coordinates) {
            std::cout << "Enter point\n";
            std::cin >> mmbr.x;
            std::cin >> mmbr.y;
        }
    }

    bool chek_exists() {
        double sum{ 0 };
        double mx = lenght_side(1, 2);
        for (int i = 1; i < 4; ++i) {
            mx < lenght_side(i, (i + 1) % 4) ? (mx = lenght_side(i, (i + 1) % 4), sum += mx) : (sum += lenght_side(i, (i + 1) % 4));
        }
        return (mx < sum ? true : false);
    }

    double lenght_side(int a, int b) {
        std::cout << "fack\n";
        cout << coordinates[a].x << ' ' << coordinates[a].y;
        return sqrt((coordinates[a].x - coordinates[b].x) * (coordinates[a].x - coordinates[b].x) +
                    (coordinates[a].y - coordinates[b].y) * (coordinates[a].y - coordinates[b].y));
    }

    double perimetr() {
        return lenght_side(0, 1) + lenght_side(1, 2) + lenght_side(2, 3) + lenght_side(3, 0);
    }

    double area() {
        std::cout << "areafack" << '\n';
        double temp_a = lenght_side(0, 1);
        double temp_b = lenght_side(1, 2);
        double temp_c = lenght_side(2, 3);
        double temp_d = lenght_side(3, 0);
        double temp_p = perimetr()/2;
        return sqrt((temp_p - temp_a)*(temp_p - temp_b)*(temp_p - temp_c)*(temp_p - temp_d));
    }
};

class Parralelogram : public Quadrangle {
public:
    Parralelogram(point c1, point c2, point c3, point c4) : Quadrangle(c1, c2, c3, c4) {}
    Parralelogram(int i) {
        std::cout << "Enter coordinats\n";
        input();
    }
    bool isParralelogram() {
        return (lenght_side(0, 1) == lenght_side(2, 0)) && (lenght_side(1, 2) == lenght_side(3, 0));
    }
};

void avarage_area(std::vector <Quadrangle>& quadrangleS, int n) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += quadrangleS[i].area();
    }
    std::cout << "The average area of quadrangles is " << sum/n << '\n';
}
void MinMax_area(std::vector <Parralelogram>& parralelogramS, int m) {
    double maxA = parralelogramS[0].area(), minA = parralelogramS[0].area();
    std::cout << "fack\n";
    for (int i = 1; i < m; ++i) {
        if (maxA < parralelogramS[i].area()) maxA = parralelogramS[i].area();
        else if (minA > parralelogramS[i].area()) minA = parralelogramS[i].area();
    }
    std::cout << "Max area is " << maxA;
    std::cout << "\nMin area is " << minA;
}

int main()
{
    std::vector <Quadrangle> quadrangleS;
    std::vector <Parralelogram> parralelogramS;
    int n, m;
    std::cout << "Enter n, m\n";
    std::cin >> n >> m;
    if (n) {
        std::cout << "Enter quadrangles\n";
        for (int i = 0; i < n; ++i) {
            std::cout << "quadrangles" << i << '\n';
            Quadrangle a(1);
            quadrangleS.push_back(a);
        }
        avarage_area(quadrangleS, n);
    }
    if(m){
        std::cout << "Enter parralelograms\n";
        for (int i = 0; i < m; ++i) {
            std::cout << "parralelograms" << i << '\n';
            Parralelogram a(1);
            parralelogramS.push_back(a);
        }
        cout << parralelogramS[0].area();
        double maxA = parralelogramS[0].area(), minA = parralelogramS[0].area();
        for (int i = 1; i < m; ++i) {
            if (maxA < parralelogramS[i].area()) maxA = parralelogramS[i].area();
            else if (minA > parralelogramS[i].area()) minA = parralelogramS[i].area();
        }
        std::cout << "Max area is " << maxA;
        std::cout << "\nMin area is " << minA;
    }
    return 0;
}
