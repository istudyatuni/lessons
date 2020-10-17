
#include <iostream>
using namespace std;

class matrix {
    int N, M;
    static int count;
    int** mat;
public:
    matrix() {
        N = 0;
        M = 0;
        matrix::inc_count();
    }
    matrix(int a, int b) {
        N = a;
        M = b;
        mat = new int* [N];
        for (int i = 0; i < a; ++i) {
            mat[i] = new int[M];
        }
        for (int i = 0; i < a; ++i) {
            for (int j = 0; j < b; ++j) {
                mat[i][j] = 0;
            }
        }
        matrix::inc_count();
    }
    ~matrix() {
        for (int i = 0; i < N; ++i) {
            delete[] mat[i];
        }
        delete[] mat;
        matrix::dec_count();
    }
    void transposition() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                mat[i][j] = mat[j][i];
            }
        }
    }
    static void inc_count() { ++count; }
    static void dec_count() { --count; }
    static void output_count() { cout << "Count is: " << count; }

    bool operator==(matrix k) { //сравниваем матрицы по размеру
        if (N == k.N && M == k.M)
            return true;
        else
            return false;
    }
    matrix& operator=(const matrix& k) {
        N = k.N;
        M = k.M;
        if(N == k.N && M == k.M)
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    mat[i][j] = k.mat[i][j];
                }
            }
        return (*this);
    }
    friend void matrix_output(const matrix& k);//в парметре константная ссылка на матрицу, чтобы не было ошибок счетчика объектов
};

void matrix_output(const matrix& k) {
    cout << "\nMatrix is " << endl;
    for (int i = 0; i < k.N; ++i) {
        for (int j = 0; j < k.M; ++j) {
            cout << k.mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int matrix::count = 0;

int main()
{
    matrix one(5, 5), two(6, 6), three(5, 5);
    //matrix::output_count();
    //matrix_output(one);
    //matrix_output(three);
    /*if (one == two) {
        one = two;
    }
    else {
        cout << "Matrix is not equal" << endl;
    }*/
    //cout << int(one == three) << " check";
    if (one == three) {
        one = three;
    }
    else {
        cout << "Matrix is not equal" << endl;
    }
    cout << "end";
    matrix_output(one);
    return 0;
}
