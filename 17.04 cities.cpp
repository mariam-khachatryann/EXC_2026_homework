#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct City {
    string name;
    int population;
};

bool exists(string name, vector<City>& cities) {
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i].name == name) {
            cities.erase(cities.begin() + i);
            return true;
        }
    }
    return false; 
}

int main() {
    vector<City> cities = {
        {"Tokyo", 37785000},
        {"Delhi", 32226000},
        {"Shanghai", 28516000},
        {"Sao Paulo", 22495000},
        {"Mexico City", 22400000},
        {"Cairo", 22183000},
        {"Mumbai", 24973000},
        {"Beijing", 21893000},
        {"Dhaka", 23210000},
        {"Osaka", 19013000},
        {"New York", 18804000},
        {"Karachi", 17360000},
        {"Buenos Aires", 15625000},
        {"Chongqing", 16875000},
        {"Istanbul", 15636000},
        {"Kolkata", 14974000},
        {"Manila", 13923000},
        {"Lagos", 15388000},
        {"Rio de Janeiro", 13458000},
        {"Tianjin", 13245000},
        {"Kinshasa", 15100000},
        {"Guangzhou", 13081000},
        {"Los Angeles", 12458000},
        {"Moscow", 12655000},
        {"Shenzhen", 12530000},
        {"Lahore", 13095000},
        {"Bangalore", 12327000},
        {"Paris", 11020000},
        {"Bogota", 10740000},
        {"Jakarta", 33756000},
        {"Chennai", 10971000},
        {"Lima", 10750000},
        {"Bangkok", 10539000},
        {"Seoul", 9976000},
        {"Nagoya", 9500000},
        {"Hyderabad", 10494000},
        {"London", 9304000},
        {"Tehran", 8847000},
        {"Chicago", 8604000},
        {"Chengdu", 9470000},
        {"Nanjing", 9320000},
        {"Wuhan", 11212000},
        {"Ho Chi Minh City", 8993000},
        {"Ahmedabad", 8450000},
        {"Kuala Lumpur", 8100000},
        {"Hong Kong", 7500000},
        {"Barcelona", 5585000},
        {"Madrid", 6669000},
        {"Toronto", 6313000},
        {"Sydney", 5312000},
        {"Erevan", 1000000}
    };

    bool game = true;

    while (game) {
        string input_city;

        while (true) {
            cout << "Enter city: ";
            getline(cin, input_city);

            if (input_city == "Finish") {
                game = false;
                break;
            }

            if (exists(input_city, cities)) {
                break;
            } else {
                cout << "Try again!" << endl;
            }
        }

        if (!game) {
            break;
        }

        char last_letter = toupper(input_city.back());
        bool found = false;

        for (int i = 0; i < cities.size(); i++) {
            if (cities[i].name[0] == last_letter) {
                cout << cities[i].name << endl;
                cities.erase(cities.begin() + i);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "You win!" << endl;
            game = false;
        }
    }
}