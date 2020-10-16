#include <iostream>
#include <cmath>
using namespace std;
class point { //class for coordinates
	double x, y;
public:
	point(double a = 0, double b = 0) {
		x = a;
		y = b;
	}
	friend ostream& operator<<(ostream& os, const point& a);
	friend istream& operator>>(istream& is, point& a);
	// assignment
	void ass(double a, double b) {
		x = a;
		y = b;
	}
	double getx(){
		return x;
	}
	double gety(){
		return y;
	}
};
ostream& operator<<(ostream& os, const point& a){
	os << '(' << a.x << ", " << a.y << ')';
	return os;
}
istream& operator>>(istream& is, point& a) {
	is >> a.x >> a.y;
	return is;
}

class line{
	point p, v; //x, y -> p.x, p.y   |   x_v, y_v -> v.x, v.y
    //distance btw two points in 2d
	double dis_two_points(double a1, double b1, double a2, double b2) {
		return sqrt(fabs((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)));
	}
public:
	static int counter; //counter for number objects
	static void inc_count(){ counter++; }
	static void dec_count(){ counter--;	}
	line(double a = 0, double b = 0, double a_v = 0, double b_v = 0){
		//x = a, y = b, x_v = a_v, y_v = b_v;
		p.ass(a, b);
		v.ass(a_v, b_v);
		inc_count();
	}
	line(const line& a) {
		//x = a.x, y = a.y, x_v = a.x_v, y_v = a.y_v;
		p = a.p;
		v = a.v;
		inc_count();
	}
	int cross(line a){
		//if(x_v==0 && a.x_v==0) return 0;
		if (v.getx() == 0 && v.gety() == 0) return 0;

		//if(x_v==0 || a.x_v==0) return 1;
		if (v.getx() == 0 || v.gety() == 0) return 1;

		//return !(y_v/x_v == a.y_v/a.x_v);
		return !(v.gety() / v.getx() == a.v.gety() / a.v.getx());
	}
	//distance btw point and line (find length normal line to *this line)
	double dis(double x1, double y1) {
		//line n(a, b, y, -x);
		//coord normal (y, -x)
		//if (y_v == 0) return fabs(y - y1);
		if (v.getx() == 0) return fabs(p.gety() - y1);

		//if (x_v == 0) return fabs(x - x1);
		if (v.getx() == 0) return fabs(p.getx() - x1);
		//double x_res = (y1 - y + (x_v / y_v) * x + (y_v / x_v) * x1) / ((x_v / y_v) + (y_v / x_v));
		//double y_res = y + (y_v / x_v) * (x_res - x);
		double x_res = (y1 - p.gety() + (v.getx() / v.gety()) * p.getx() + (v.gety()
					/ v.getx()) * x1) / ((v.getx() / v.gety()) + (v.gety() / v.getx()));
		double y_res = p.gety() + (v.gety() / v.getx()) * (x_res - p.getx());
		return dis_two_points(x1, y1, x_res, y_res);
	}
	friend istream& operator>>(istream& is, line& b);
	friend ostream& operator<<(ostream& os, const line &b);
	~line(){ dec_count(); }

};

istream& operator>>(istream& is, line& b) {
	//is >> b.x >> b.y >> b.x_v >> b.y_v;
	is >> b.p >> b.v;
	return is;
}



ostream& operator<<(ostream& os, const line &a){
	//cout << '(' << a.x << ", " << a.y << ") (" << a.x_v << ", " << a.y_v << ")";
	cout << a.p << ' ' << a.v;
	return os;
}

int line::counter = 0;

int main()
{
	line a, b;
	cin >> a >> b;
	cout << a << endl << b << endl;
	cout << a.cross(b) << ' ' << line::counter << endl;
    cout << "enter point: ";
    double x, y;
    cin >> x >> y;
    cout << "distance = " << a.dis(x, y) << endl;
	return 0;
}
