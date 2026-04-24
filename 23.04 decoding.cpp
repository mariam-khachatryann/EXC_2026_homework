#include <iostream>
#include <string>
using namespace std;

void decode(string s, int i, string current) {
    if (i == s.length()) {
        cout << current << endl;
        return;
    }

    if (s[i] == '0'){
        return;
    }

    int num1 = s[i] - '0';
    char c1 = 'A' + num1 - 1;
    decode(s, i + 1, current + c1);

    if (i + 1 < s.length()) {
        int num2 = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (num2 <= 26) {
            char c2 = 'A' + num2 - 1;
            decode(s, i + 2, current + c2);
        }
    }
}

int main() {
    string s;
    cin >> s;

    decode(s, 0, "");

    return 0;
}