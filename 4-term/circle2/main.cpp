#include <iostream>
#include <cmath>
using namespace std;
class circle{
	double x, y, r;
	double dis_two_points(double a1, double b1, double a2, double b2){ //distance btw two points in 2d
		return sqrt(fabs((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2)));
	}
public:
	static int count; //counter for number objects
	static void inc_count(){
		count++;
	}
	static void dec_count(){
		count--;
	}
	void input(){
		cout << "enter x, y, r: ";
		cin >> x >> y >> r;
	}
	circle(bool){
		input();
		inc_count();
	}
	circle(double a = 0, double b = 0, double c = 0){
		x = a;
		y = b;
		r = c;
		inc_count();
	}
	circle(const circle& a){
		x = a.x;
		y = a.y;
		r = a.r;
		inc_count();
	}
	void rewrite(double a, double b, double c){
		x = a;
		y = b;
		r = c;
	}

	friend ostream& operator<<(ostream& os, const circle &a);

	int is_cross(circle a){ //circles crossing or not
		int c = dis_two_points(x, y, a.x, a.y);
		if (c == r + a.r) return 1; //if circles touching
		double max_r, min_r;
		if (r > a.r){
			max_r = r;
			min_r = a.r;
		}
		else {
			max_r = a.r;
			min_r = r;
		}
		//one of two circles in other
		if (max_r > (min_r + c) && c < max_r) return 0;

		//all other cases
		if (c < r + a.r) return 1;
		return 0;
	}
	~circle(){
		dec_count();
	}
};
ostream& operator<<(ostream& os, const circle &a){
	cout << '(' << a.x << ", " << a.y << "), r = " << a.r;
	return os;
}
int return_count(){
	return circle::count;
}
int circle::count = 0;
int main(){
	circle a(7, 7, 2), b(3, 3, 2);
	cout << "circle far from each other:\n";
	cout << "a: " << a << "; b: " << b << endl;
	if(a.is_cross(b)) cout << "a cross b\n";
	else cout << "a not cross b\n";

	a.rewrite(1, 2, 4); b.rewrite(1, 4, 2);
	cout << "circles touch:\n";
	cout << "a: " << a << "; b: " << b << endl;
	if(a.is_cross(b)) cout << "a cross b\n";
	else cout << "a not cross b\n";

	a.rewrite(3, 6, 6); b.rewrite(4, 4, 1);
	cout << "circle in other circle:\n";
	cout << "a: " << a << "; b: " << b << endl;
	if(a.is_cross(b)) cout << "a cross b\n";
	else cout << "a not cross b\n";

	a.rewrite(2, 5, 4); b.rewrite(3, 3, 2);
	cout << "circle's center in other circle:\n";
	cout << "a: " << a << "; b: " << b << endl;
	if(a.is_cross(b)) cout << "a cross b\n";
	else cout << "a not cross b\n";

	a.rewrite(1, 1, 2); b.rewrite(3, 3, 3);
	cout << "a: " << a << "; b: " << b << endl;
	if(a.is_cross(b)) cout << "a cross b\n";
	else cout << "a not cross b\n";
	return 0;
}
