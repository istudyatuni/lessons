#include <iostream>
#include <vector>
using namespace std;

class Matrix {
    int m, n;//m - vertical
    vector<vector<double>> matrix;
public:
    static int count;
    static void inc_count() {
        Matrix::count++;
    }
    static void dec_count() {
        Matrix::count--;
    }
    Matrix() : m{0}, n{0}{
        inc_count();
    }
    Matrix(int a, int b): m{a}, n{b}{
        matrix.reserve(m * n);
        vector<double> tmp(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                tmp[j] = i + j;
            }
            matrix.push_back(tmp);
        }
        inc_count();
    }

    friend ostream& operator<<(ostream &os, const Matrix &a);
    //
    int operator>(Matrix& a) {
        if (this->m > a.m && this->n > a.n)
            return 1;
        return 0;
    }
    int operator<(Matrix& b) {
        if (b > (*this))
            return 1;
        return 0;
    }
    //
    int operator>=(Matrix& a) {
        if (this->m >= a.m && this->n >= a.n)
            return 1;
        return 0;
    }
    int operator<=(Matrix& b) {
        if (b >= (*this))
            return 1;
        return 0;
    }

    int operator==(Matrix& a) {
        if (this->m == a.m && this->n == a.n)
            return 1;
        return 0;
    }

    Matrix& operator=(Matrix& a) {
        m = a.m;
        n = a.n;
        this->matrix = a.matrix;
        return (*this);
    }

    Matrix& operator=(vector<vector<double>>& a) {
        if (!a.empty()) {
            cout << "enter size matrix, m and n: ";
            cin >> m >> n;
        }
        else {
            m = n = 0;
            return *this;
        }
        matrix = a;
        return *this;
    }

    void transposition() {
        if (m != n || n == 0 || m % 2 != 0) {
            cout << "\nerror! матрица не квадратная и количество строк не четно\n";
            exit(0);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    ~Matrix() {
        dec_count();
    }
};

ostream& operator<<(ostream &os, const Matrix &a) {
    cout << '\n' << a.m << 'x' << a.n << ":\n";
    for (int i = 0; i < a.m; ++i) {
        for (int j = 0; j < a.n; ++j) {
            os << a.matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return os;
}

int Matrix::count = 0;
int getCount() {
    return Matrix::count;
}

int main() {
    cout << "start\n";
    Matrix a, c;
    vector<vector<double>> v = {{1, 5, 2, 5}, {7, 6, 16, 98}, {9, 87, 1, 7}, {5, 3, 65, 12}};
    c = v;
    Matrix b(6, 6);
    cout << a << b << c;
    cout << "count = " << getCount();
    a = b;
    c.transposition();
    cout << a << b << c;
    return 0;
}
