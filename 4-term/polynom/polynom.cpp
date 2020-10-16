#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class polynom {
	int n; //max power
	vector<double>mas;
	/*
		степени по убыванию!
	*/
public:
	polynom(int b){
		if(b)
			input(b);
		else random();
	}
	polynom(int a, bool b){
		n = a;
		mas.reserve(a + 1);
	}
	void input(int a){
		if(a < 0){
			a = -a;	//cout << "size < 0! changed sign\n"
		}
		if (a < 2){
			cout << "it's not polynom\n";
			return;
		}
		n = a;
		mas.reserve(n + 10);
		double t;
		cout << "enter polynom power = " << n << ":\n";
		for (int i = n; i >= 0; --i){
			cin >> t;
			mas.push_back(t);
		}
		reverse(mas.begin(), mas.end());// чтобы степени убывали по порядку ввода
		print();
	}
	void print(){
		for (int i = n; i >= 0; --i){
			if (mas[i]) // if = 0, not print
				if (i == n)
					cout << noshowpos << mas[i] << "x^" << i;
				else if (i == 0)
					cout << showpos << mas[i];
				else if (i == 1)
					cout << showpos << mas[i] << "x";
				else cout << showpos << mas[i] << "x^" << noshowpos << i;
		}
		cout << "\ncoefficients:";
		for (int i = n; i >= 0; --i)
			if (mas[i])
				cout << noshowpos << mas[i] << ' ';
		cout << endl;
	}
	void random(){
		n = rand() % 3 + 3;
		cout << "n = " << n << '\n';
		for (int i = 0; i <= n; ++i){
			mas.push_back(rand() % 9 + 1);
		}
		print();
	}
	polynom operator+(polynom b){
		int x, y;//0...x..y
		int k;
		if (n > b.n){
			x = b.n;
			y = n;
			//res.n = y;
			k = 0;
		}
		if (n < b.n) {
			x = n;
			y = b.n;
			k = 1;
		}
		polynom res(y, true);
		if (n == b.n){//lengths is equal
			res.n = n;
			for (int i = 0; i <= res.n; i++)
				res.mas.push_back(mas[i] + b.mas[i]);
		} else {
			for (int i = 0; i <= x; ++i)
				res.mas.push_back(mas[i] + b.mas[i]);
			if (k == 0)//a > b
				for (int i = x + 1; i <= y; ++i)
					res.mas.push_back(mas[i]);
			else
				for (int i = x + 1; i <= y; ++i)
					res.mas.push_back(b.mas[i]);
		}
		return res;
	}
	polynom operator+=(polynom b){
		return *this + b;
	}
	polynom operator*(polynom b){
		polynom res((n + b.n), true);
		for (int k = 0; k <= res.n; ++k)
			res.mas.push_back(0);
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= b.n; ++j)
					res.mas[i + j] += mas[i] * b.mas[j];
		return res;
	}
	polynom operator-(polynom b){
		for (int i = 0; i <= b.n; ++i)
			b.mas[i] = -b.mas[i];
		return *this + b;
	}
	polynom operator-=(polynom b){
		return *this - b;
	}
	ostream& operator<<(ostream os, polynom a){
		for (int i = a.n; i >= 0; --i){
			if (a.mas[i]) // if = 0, not print
				if (i == a.n)
					cout << noshowpos << a.mas[i] << "x^" << i;
				else if (i == 0)
					cout << showpos << a.mas[i];
				else if (i == 1)
					cout << showpos << a.mas[i] << "x";
				else cout << showpos << a.mas[i] << "x^" << noshowpos << i;
		}
		cout << "\ncoefficients:";
		for (int i = a.n; i >= 0; --i)
			if (a.mas[i])
				cout << noshowpos << a.mas[i] << ' ';
		cout << endl;
	}
};

int main(){
	srand(time(0));
	polynom a(5);
	polynom b(3);
	//a = a + b;
	cout << "sum:\n";
	(a + b).print();
	(a - b).print();
	a = a * b;
	cout << "mul:\n";
	a.print();
	cout << b;
	return 0;
}
