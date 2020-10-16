#include <iostream>
#include <cmath>
#include <vector>
#define PI 3.14159265
using namespace std;
class sphere {
	double x, y, z;
	double rad;//      1: x          y          z,   2:    x          y          z
	double dis_two_points(double a1, double b1, double c1, double a2, double b2, double c2){ //distance btw two points in 3d
		return sqrt(fabs((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2) + (c1 - c2) * (c1 - c2)));
	}
public:
	static int count; //counter for number objects
	static void inc_count(){
		count++;
	}
	static void dec_count(){
		count--;
	}
	sphere(int a = 0, int b = 0, int c = 0, int r = 0) {
		x = a;
		y = b;
		z = c;
		rad = r;
		inc_count();
	}
	sphere(const sphere& a) {
		x = a.x;
		y = a.y;
		z = a.z;
		rad = a.rad;
		inc_count();
	}
	int is_cross(sphere a) {
		double r = dis_two_points(x, y, z, a.x, a.y, a.z);
        double max_r, min_r;
        (rad > a.rad)?(max_r = rad, min_r = a.rad):(max_r = a.rad, min_r = rad);
        return r <= r + a.rad && max_r <= min_r + r;
	}
	friend istream& operator>>(istream& is, sphere& b);
	friend ostream& operator<<(ostream& os, const sphere &b);
	~sphere() {
		dec_count();
	}
	
};
istream& operator>>(istream& is, sphere& b) {
	is >> b.x >> b.y >> b.z >> b.rad;
	return is;
}
ostream& operator<<(ostream& os, const sphere &a){
	cout << '(' << a.x << ", " << a.y << ", " << a.z << "), r = " << a.rad;
	return os;
}
int is_count(){
	return sphere::count;
}
int sphere::count = 0;
int main() {
    sphere a, b;
    //cin >> a >> b;
    //cout << a.is_cross(b) << endl << is_count();
    vector<sphere> v;
    cout << "enter size: ";
    int sz;
    cin >> sz;
    for (int i = 0; i < sz; ++i) {
    	cin >> a;
    	v.push_back(a);
    }
    for (int i = 0; i < sz; ++i) {
    	cout << v[i] << endl;
    }
    cout << "count = " << is_count();
    return 0;
}
