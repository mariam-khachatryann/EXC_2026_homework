#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    vector<string> words = {"eat", "tea", "tan", "ate","nat", "bat"};

    unordered_map<string, vector<string>> mp;

    for (string word : words) {
        int count[26] = {0};

        for (char c : word) {
            count[c - 'a']++;
        }

        string key = "";
        for (int i = 0; i < 26; i++) {
            key += to_string(count[i]) + "#";
        }

        mp[key].push_back(word);
    }
    
    cout << "[ ";
    
    for (auto it : mp) {
        cout << "[ ";

        for (string w : it.second) {
            cout << "\"" << w << "\" ";
        }

        cout << "],";
    }
    cout << "]";
}