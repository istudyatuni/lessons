#include <iostream>
#include <cmath>
using namespace std;
class line{
    double x, y, x_v, y_v;
    //distance btw two points in 2d
	double dis_two_points(double a1, double b1, double a2, double b2) {
		return sqrt(fabs((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)));
	}
public:
    static int counter; //counter for number objects
	static void inc_count(){ counter++; }
	static void dec_count(){ counter--;	}
	line(int a = 0, int b = 0, int a_v = 0, int b_v = 0){
	    x = a, y = b, x_v = a_v, y_v = b_v;
	    inc_count();
	}
	line(const line& a) {
		x = a.x, y = a.y, x_v = a.x_v, y_v = a.y_v;
		inc_count();
	}
	int cross(line a){
		//lines vertical and parallel:
	    if(x_v==0 && a.x_v==0) return 0;

	    //one line is vertical, other is not, => lines is cross
	    if(x_v==0 || a.x_v==0) return 1;

	    //if angle coeffs is equal, return 0
	    return !(y_v/x_v == a.y_v/a.x_v);
	}
	//distance btw point and line (find length normal line to *this line)
	double dis(double x1, double y1) {
		//line n(a, b, y, -x);
		//coord normal (y, -x)
		if (y_v == 0) return fabs(y - y1);
		if (x_v == 0) return fabs(x - x1);
		double x_res = (y1 - y + (x_v / y_v) * x + (y_v / x_v) * x1) / ((x_v / y_v) + (y_v / x_v));
		double y_res = y + (y_v / x_v) * (x_res - x);
		return dis_two_points(x1, y1, x_res, y_res);
	}
	friend istream& operator>>(istream& is, line& b);
	friend ostream& operator<<(ostream& os, const line &b);
	~line(){ dec_count(); }

};

istream& operator>>(istream& is, line& b) {
	is >> b.x >> b.y >> b.x_v >> b.y_v;
	return is;
}
ostream& operator<<(ostream& os, const line &a){
	cout << '(' << a.x << ", " << a.y << ") (" << a.x_v << ", " << a.y_v << ")";
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
