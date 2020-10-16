#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int n = 10;
    vector<int> a;
    for (int i = 0; i < n; ++i){
        a.push_back(rand()%100);
        cout << a[i] << ' ';
    }
    cout << "\nafter sorting:\n";
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    return 0;
}
