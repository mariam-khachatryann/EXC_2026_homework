#include <iostream>
#include <vector>
using namespace std;

struct Obj {
    int id;
    string person;
    int last_update;
};

int findById(vector<Obj>& v, int id) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i].id == id) {
            return i;
        }
    }
    return -1;
}

void sync(vector<Obj>& A, vector<Obj>& B, int& last_sync_time) {

    for (Obj a : A) {
        if (a.last_update > last_sync_time) {

            int index = findById(B, a.id);

            if (index == -1) {
                B.push_back(a);
            } else {
                if (a.last_update > B[index].last_update) {
                    B[index] = a;
                }
            }
        }
    }

    for (Obj b : B) {
        if (b.last_update > last_sync_time) {

            int index = findById(A, b.id);

            if (index == -1) {
                A.push_back(b);
            } else {
                if (b.last_update > A[index].last_update) {
                    A[index] = b;
                }
            }
        }
    }

    int mx = last_sync_time;

    for (Obj a : A) {
        if (a.last_update > mx) {
            mx = a.last_update;
        }
    }

    for (Obj b : B) {
        if (b.last_update > mx) {
            mx = b.last_update;
        }
    }

    last_sync_time = mx;
}

void print(vector<Obj>& v) {
    for (Obj x : v) {
        cout << x.id << " " << x.person << " " << x.last_update << endl;
    }
    cout << endl;
}

int main() {

    vector<Obj> A = {
        {1, "Anna", 1},
        {2, "Gevorg", 5},
        {3, "Nane", 3},
        {5, "Ella", 7},
        {7, "Gor", 6},
        {9, "Vahe", 10}
    };

    vector<Obj> B = {
        {2, "Gevorg", 2},
        {4, "David", 4},
        {6, "Hayk", 8},
        {7, "Gor", 5},
        {8, "Hasmik", 9},
        {10, "Karen", 11}
    };

    int last_sync_time = 0;

    sync(A, B, last_sync_time);

    print(A);
    print(B);

    return 0;
}