#include <iostream>
#include <cmath>
using namespace std;

void count_min_x(int n) {
    if (n <= 0) {
        cout << "Not valid n!" << endl;
    } else {
        double raw_x = (-1.0 + sqrt(1.0 + 8.0 * n)) / 2.0;
        int x = (int)ceil(raw_x);
        
        cout << "minimum count of experiments (x) >= " << x << endl;
    }
}

int main() {
    count_min_x(100); 
    count_min_x(10); 
    return 0;
}