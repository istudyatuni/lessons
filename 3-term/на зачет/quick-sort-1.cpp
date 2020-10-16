#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
void quick(vector<int>& a, int left, int right);
int main(){
	srand(time(0));
	int n = 10;
	vector<int> a;
	for (int i = 0; i < n; ++i){
		a.push_back(rand()%100);
		cout << a[i] << ' ';
	}
	cout << "\nafter sorting:\n";
	quick(a, 0, n - 1);
	for (int i = 0; i < n; ++i)
		cout << a[i] << ' ';
	return 0;
}
void quick(vector<int>& a, int left, int right){
	int i = left, j = right, mid = a[(left + right) / 2];
	while (i <= j){
		while (a[i] < mid) ++i;
		while (a[j] > mid) --j;
		if (i <= j){
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	if (left < j) quick(a, left, j);
	if (right > i) quick(a, i, right);
}