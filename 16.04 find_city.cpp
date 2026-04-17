#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct City {
    int id;
    string city;
    string country;
    int population;
    double lat;
    double lng;
};

bool compare(double a, string op, double b) {
    if (op == "<") {
        return a < b;
    }
    if (op == "<=") {
        return a <= b;
    }
    if (op == "==") {
        return a == b;
    }
    if (op == ">") {
        return a > b;
    }
    if (op == ">=") {
        return a >= b;
    }
    return false;
}

int getPopulation(string name, vector<City>& a) {
    for (auto c : a) {
        if (c.city == name)
            return c.population;
    }
    return -1;
}

int main() {
    vector<City> a = {
        {1, "Yerevan", "Armenia", 1000000, 40.18, 44.51},
        {2, "Gyumri", "Armenia", 120000, 40.78, 43.84},
        {3, "Moscow", "Russia", 12000000, 55.75, 37.61},
        {4, "Paris", "France", 2100000, 48.85, 2.35}
    };

    string input;
    cin >> input;

    string field = "", op = "", value = "";
    int i = 0;

    while (i < input.size() && isalpha(input[i])) {
        field += input[i];
        i++;
    }

    if (input[i] == '<' || input[i] == '>' || input[i] == '=') {
        op += input[i];
        i++;

        if (i < input.size() && input[i] == '=') {
            op += input[i];
            i++;
        }
    }

    while (i < input.size()) {
        value += input[i];
        i++;
    }

    for (auto c : a) {

        if (field == "population") {
            int val = stoi(value);

            if (compare(c.population, op, val))
                cout << c.city << endl;
        }

        else if (field == "country") {
            if (op == "==" && c.country == value)
                cout << c.city << endl;
        }

        else if (field == "lat") {
            double val = stod(value);

            if (compare(c.lat, op, val))
                cout << c.city << endl;
        }

        else if (field == "lng") {
            double val = stod(value);

            if (compare(c.lng, op, val))
                cout << c.city << endl;
        }
        else if (field == "city") {
            int targetPop = getPopulation(value, a);

            if (compare(c.population, op, targetPop))
                cout << c.city << endl;
        }
    }

    return 0;
}