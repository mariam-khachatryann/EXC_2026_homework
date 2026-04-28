#include <iostream>
#include <vector>
#include <string>
using namespace std;

void extract(const string& s, int& pos, vector<string>& names, vector<int>& scores) {
    while (pos < s.size()) {

        if (s.substr(pos, 10) == "\"fullName\"") {
            pos = s.find('"', pos + 10) + 1;
            int end = s.find('"', pos);
            names.push_back(s.substr(pos, end - pos));
            pos = end;
        }

        else if (s.substr(pos, 8) == "\"points\"") {
            pos = s.find(':', pos) + 1;

            while (pos < s.size() && (s[pos] == ' ' || s[pos] == '\n')){
                    pos++;
            }

            int num = 0;
            while (pos < s.size() && isdigit(s[pos])) {
                num = num * 10 + (s[pos] - '0');
                pos++;
            }
            scores.push_back(num);
        }

        else if (s.substr(pos, 7) == "\"child\"") {
            pos = s.find('{', pos);
            extract(s, pos, names, scores);
        }

        else if (s[pos] == '}') {
            pos++;
            continue;
        }

        else {
            pos++;
        }
    }
}

int main() {
    string data = R"(
 [
   {
     "fullName": "John Smith",
     "points": 20,
     "child": {
       "fullName": "Michael Brown",
       "points": 25,
       "child": {
         "fullName": "David Wilson",
         "points": 14
       }
     }
   },
   {
     "fullName": "Emma Johnson",
     "points": 30
   },
   {
     "fullName": "Olivia Davis",
     "points": 22,
     "child": {
       "fullName": "James Miller",
       "points": 18
     }
   }
 ]
 )";

    vector<string> names;
    vector<int> scores;

    int pos = 0;
    extract(data, pos, names, scores);

    cout << "Names:\n";
    for (auto& name : names) {
        cout << name << endl;
    }

    double sum = 0;
    for (int x : scores) {
        sum += x;
    }

    cout << "\nAverage points: " << sum / scores.size() << endl;

    return 0;
}