#include <cctype>
#include <string>
#include <iostream>
#include <stack>

using namespace std;

string trim(string s) {
    int start = 0;
    while (start < s.length() && isspace(s[start])) {
        start++;
    }

    int end = s.length() - 1;
    while (end >= 0 && isspace(s[end])) {
        end--;
    }

    return s.substr(start, end - start + 1);
}

string text = "";
stack<string> history;

void type(string s) {
    history.push(text);
    s = trim(s);
    text += s;
}

void delete_k(int k) {
    history.push(text);
    if (k > text.length()){
        cout << "Invalid delete!\n";
    }
    else {
        text.erase(text.length() - k, k);
    }
}

void print() {
    cout << text << endl;
}

void undo() {
    if (!history.empty()) {
        text = history.top();
        history.pop();
    }
}

int main() {
    type("hello");
    print(); 

    type(" world");
    print(); 

    delete_k(12);
    print(); 

    undo();
    print(); 
}