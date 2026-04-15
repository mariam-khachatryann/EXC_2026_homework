#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

string convert(string num, int base1, int base2) {
    int number = 0;
    int length = num.size();

    for (int i = 0; i < length; i++) {
        int n = num[i] - '0';
        number += n * pow(base1, length - i - 1);
    }

    if (number == 0) {
        return "0";
    }

    string result = "";

    while (number > 0) {
        result += char((number % base2) + '0');
        number /= base2;
    }

    reverse(result.begin(), result.end());

    return result;
}

int main() {
    cout << convert("100100", 2, 3);
    return 0;
}