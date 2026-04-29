#include <iostream>
using namespace std;

void print(int arr[8][8]) {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            cout << arr[x][y] << ' ';
        }
        cout << endl;
    }
    cout << "------------------------\n";
}

int dir_i[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dir_j[8] = {1, -1, 2, 2, 1, -1, -2, -2};

bool is_valid(int arr[8][8], int i, int j) {
    return (i >= 0 && i < 8 && j >= 0 && j < 8 && arr[i][j] == -1);
}

int degree(int arr[8][8], int i, int j) {
    int count = 0;
    for (int k = 0; k < 8; k++) {
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];
        if (is_valid(arr, ni, nj)) {
            count++;
        }
    }
    return count;
}

bool move(int arr[8][8], int i, int j, int step) {
    if (step == 64) {
        print(arr);
        return true;
    }

    int best_k[8];
    int best_deg[8];

    for (int k = 0; k < 8; k++) {
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];

        if (is_valid(arr, ni, nj)) {
            best_k[k] = k;
            best_deg[k] = degree(arr, ni, nj);
        } else {
            best_deg[k] = 100; // invalid
        }
    }

    for (int a = 0; a < 8; a++) {
        for (int b = a + 1; b < 8; b++) {
            if (best_deg[a] > best_deg[b]) {
                swap(best_deg[a], best_deg[b]);
                swap(best_k[a], best_k[b]);
            }
        }
    }

    for (int x = 0; x < 8; x++) {
        int k = best_k[x];
        int ni = i + dir_i[k];
        int nj = j + dir_j[k];

        if (is_valid(arr, ni, nj)) {
            arr[ni][nj] = step;

            if (step % 10 == 0) {
                print(arr);
            }

            if (move(arr, ni, nj, step + 1)) return true;

            arr[ni][nj] = -1;
        }
    }

    return false;
}

int main() {
    int arr[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            arr[i][j] = -1;

    arr[0][0] = 0;

    if (!move(arr, 0, 0, 1)) {
        cout << "Don't have solution!\n";
    }

    return 0;
}