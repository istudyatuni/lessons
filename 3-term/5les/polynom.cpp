#include <bits/stdc++.h>
using namespace std;
struct pol {
    int n;
    vector<int>p;
};

pol input();
void out (pol a);
pol add (pol a, pol b);
pol mul (pol a, pol b);

int main(){
    pol a, b;
    a = input();
    if(a.n<2)return 1;
    b = input();
    if(b.n<2)return 1;
    cout<<"sum = ";
    out(add(a, b));
    cout << "mul = ";
    out(mul(a, b));
    return 0;
}
pol input(){
    pol b;
    //cout << "enter n: ";
    cin >> b.n;
    if (b.n < 2){
    	cout << "it is not polynome!";
    }
    int t;
    for (int i = 0; i < b.n; ++i){
        cin >> t;
        b.p.push_back(t);
    }
    cout << endl;
    return b;
}
void out (pol a){
    for (int i = a.n - 1; i >= 0; --i){
    	if (a.p[i])
	    	if (i == a.n - 1) 
	    		cout << noshowpos << a.p[i] << "x^" << i;
	    	else if (i == 0)
	    		cout << showpos << a.p[i];
	        else cout << showpos << a.p[i] << "x^" << noshowpos << i;
    }
    cout << "\ncoefficients:";
    for (int i = a.n - 1; i >= 0; --i)
    	if (a.p[i])
    		cout << noshowpos << a.p[i] << ' ';
    cout << endl;
}
pol add (pol a, pol b){
    pol res;
    int x, y;//0...x..y
    int k;
    if (a.n > b.n){
        x = b.n;
        y = a.n;
        res.n = y;
        k = 0;
    }
    if (a.n < b.n) {
        x = a.n;
        y = b.n;
        res.n = y;
        k = 1;
    }
    if (a.n == b.n){//lengths is equal
        res.n = a.n;
        for (int i = 0; i < res.n; i++){
            res.p.push_back(a.p[i] + b.p[i]);
        }
    } else {
		for (int i = 0; i < x; ++i){
			res.p.push_back(a.p[i] + b.p[i]);
		}
		if (k == 0)//a > b
			for (int i = x; i < y; ++i){
				res.p.push_back(a.p[i]);
			}
		else 
			for (int i = x; i < y; ++i){
				res.p.push_back(b.p[i]);
			}
    }
    return res;
}
pol mul (pol a, pol b){
	pol res;
	res.n = (a.n - 1)*(b.n - 1) + 1;
	for (int k = 0; k < res.n; ++k){
		res.p.push_back(0);
		for (int i = 0; i < a.n; ++i){
			for (int j = 0; j < b.n; ++j){
				if (i + j == k)
					res.p[k] += a.p[i] * b.p[j];
			}
		}
	}
	return res;
}