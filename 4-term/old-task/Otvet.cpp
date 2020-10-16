#include <vector>
#include <iostream>

class Matrix {
private:
    static int count;
    int m_N, m_M;
    //int** mtrx;
    std::vector<std::vector<int>> mtrx;
public:

    Matrix(int n = 0, int m = 0) : m_N(n), m_M(m) {
        /*mtrx = new int* [n];
        for (int i = 0; i < n; ++i) { mtrx[i] = new int[m]; }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                mtrx[i][j] = 0;
            }
        }*/
        mtrx.resize(n);
        for (int i = 0; i < n; ++i) {mtrx[i].resize(m);}
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {mtrx[i][j] = 0;}
        }
        Matrix::inc_count();
    }
    ~Matrix() {
        /*for (int i = 0; i < (*this).m_N; ++i) { delete[] mtrx[i]; }
        delete[] mtrx;*/
        Matrix::dec_count();
    }

    static void inc_count() { ++count; }
    static void dec_count() { --count; }
    static void output_count() { std::cout << "The instance count is " << count << '\n'; }

    void transposition() {
        for (int i= 0; i < (*this).m_N; ++i) { //цикл по строкам
            for (int j = 0; j < (*this).m_M; ++j) { //цикл по столбцам
                std::swap((*this).mtrx[i][j], (*this).mtrx[j][i]);
            }
        }
    }

    void operator=(Matrix prmtr_matrix) {
        for (int i = 0; i < (*this).m_N; ++i) {
            for (int j = 0; j < (*this).m_M; ++j) {
                (*this).mtrx[i][j] = prmtr_matrix.mtrx[i][j];
            }
        }
    }
    bool operator==(Matrix prmtr_matrix) {
        return ((*this).m_M == prmtr_matrix.m_M) && ((*this).m_N == prmtr_matrix.m_N);
    }

    friend void matrix_output(const Matrix &prmtr_matrix);
};


void matrix_output(const Matrix &prmtr_matrix) {
    std::cout << "Your matrix is\n";
    Matrix::output_count();
    for (int i = 0; i < prmtr_matrix.m_N; ++i) {
        for (int j = 0; j < prmtr_matrix.m_M; ++j) { std::cout << prmtr_matrix.mtrx[i][j] << ' '; }
        std::cout << '\n';
    }
    Matrix::output_count();
}


int Matrix::count = 0;

int main()
{
    Matrix test_matrix1(5, 5), test_matrxix2(6, 6);
    matrix_output(test_matrix1);
    Matrix::output_count();
    return 0;
}