#include <iostream>
#include <limits>
using namespace std;

bool binarySearch(int arr[], int left, int right, int target) {
    if (left > right) {
        return false; 
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return true; 
    }

    if (arr[mid] < target) {
        return binarySearch(arr, mid + 1, right, target);
    }

    return binarySearch(arr, left, mid - 1, target);
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    cout << "Enter number: ";
    cin >> target;
    
    while (!(cin >> target)) {
        cout << "Wrong enter, write int: ";

        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (binarySearch(arr, 0, n - 1, target)) {
        cout << "Is in array\n";
    } else {
        cout << "Not in array\n";
    }

    return 0;
}