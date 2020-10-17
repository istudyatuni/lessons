#include <bits/stdc++.h>
using namespace std;
struct vect{
    int n;
    float* mas;
};
struct matrix{
    int m, n; /// m = i, n = j
    float** mas;
};
/// prototype
vect make_vect(int sz);
void print_vect (vect a);
vect average_vect (matrix a);///average columns
void rand_vect (vect &a);

matrix make_matrix (int m, int n);
void rand_matrix (matrix &a);
void print_matrix (matrix &a);
vect search_j (matrix &a, int j);///search column j
matrix vect_to (vect a1, vect a2, vect a3);///3 vector to matrix

int main(){
    matrix a;
    rand_matrix(a);
    cout << "matrix:\n";
    print_matrix(a);
    vect b = average_vect(a);
    cout << "vector with average:\n";
    print_vect(b);
    cout << "search 3 column:\n";
    b = search_j(a, 3);
    print_vect(b);
    vect d, c, f;
    cout << "3 random vectors:\n";
    rand_vect(d);
    rand_vect(f);
    rand_vect(c);
    print_vect(d);
    print_vect(f);
    print_vect(c);
    cout << "matrix from 3 vectors:\n";
    a = vect_to(d, f, c);
    print_matrix(a);
    return 0;
}

/// functions for vector///

vect make_vect(int sz){
    vect res;
    res.n = sz;
    res.mas = new float [res.n];
    /*for (int i = 0; i < res.n; ++i){
        cout << i << ": ";
        cin >> res.mas[i];
    }*/
    return res;
}
void print_vect (vect &a){
    for (int i = 0; i < a.n; ++i){
        cout << a.mas[i] << ' ';
    }
    cout << endl;
}
vect average_vect (matrix a){
    vect res;
    res = make_vect(a.n);
    for (int j = 0; j < a.n; ++j){
        float sr = 0;
        for (int i = 0; i < a.m; ++i){
            sr += a.mas[i][j];
        }
        sr /= a.n;
        res.mas[j] = sr;
    }
    return res;
}
void rand_vect (vect &a){
    a = make_vect(5);
    srand(time(0));
    for (int i = 0; i < a.n; ++i){
        a.mas[i] = rand()%9 + 1;
    }
}

/// functions for matrix ///

matrix make_matrix (int m, int n){
    matrix res;
    res.m = m;
    res.n = n;
    res.mas = new float *[res.m];
    for (int i = 0; i < res.m; ++i){
        res.mas[i] = new float [res.n];
    }
    return res;
}
void rand_matrix (matrix &a){
    a = make_matrix(5, 5);
    srand(time(0));
    for (int i = 0; i < a.m; ++i){
        for (int j = 0; j < a.n; ++j){
            a.mas[i][j] = rand()%9 + 1;
        }
    }
}
void print_matrix (matrix &a){
    for (int i = 0; i < a.m; ++i){
        for (int j = 0; j < a.n; ++j)
            cout << a.mas[i][j] << ' ';
        cout << endl;
    }
}
vect search_j (matrix &a, int j){
    vect res;
    res.n = a.m;
    for (int i = 0; i < a.m; ++i){
        res.mas[i] = a.mas[i][j];
    }
    return res;
}
matrix vect_to (vect a1, vect a2, vect a3){
    matrix res;
    if (a1.n == a2.n && a2.n == a3.n)
        res = make_matrix(3, a1.n);
    else {
        res = make_matrix(0, 0);
        cout << "Error: sizes does not equals!\n";
        return res;
    }
    for (int i = 0; i < a1.n; ++i){
        res.mas[1][i] = a1.mas[i];
        res.mas[2][i] = a2.mas[i];
        res.mas[3][i] = a3.mas[i];
    }
    return res;
}
