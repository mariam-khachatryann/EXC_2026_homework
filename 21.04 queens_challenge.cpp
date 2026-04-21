#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> col; 

bool safe(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c) {
            return false;
        }
        if (abs(col[i] - c) == abs(i - row)) {
            return false; 
        }
    }
    return true;
}

void solve(int row) {
    if (row == n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (col[i] == j) cout << "Q ";
                else cout << "* ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (safe(row, c)) {
            col[row] = c;
            solve(row + 1);
        }
    }
}

int main() {
    cin >> n;

    if (n < 4) {
        cout << "n >= 4\n";
        return 0;
    }

    col.resize(n);
    solve(0);

    return 0;
}