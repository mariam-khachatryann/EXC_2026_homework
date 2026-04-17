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
    
    string input_city;

    string start_city = "Yerevan";
    cout << "Computer starts: " << start_city << endl;

    char last_letter = toupper(start_city.back());

    exists(start_city, cities);

    while (true) {
        cout << "Enter a city starting with: " << last_letter << endl;

        getline(cin, input_city);

        if (input_city.size() == 0) {
            getline(cin, input_city);
        }

        input_city[0] = toupper(input_city[0]);

        if (toupper(input_city[0]) != last_letter) {
            cout << "Wrong letter! Try again." << endl;
            continue;
        }

        if (exists(input_city, cities) == false) {
            cout << "City not found or already used. Try again." << endl;
            continue;
        }

        last_letter = toupper(input_city.back());

        int best_index = -1;
        int max_population = -1;

        for (int i = 0; i < cities.size(); i++) {
            if (toupper(cities[i].name[0]) == last_letter) {
                if (cities[i].population > max_population) {
                    max_population = cities[i].population;
                    best_index = i;
                }
            }
        }

        if (best_index == -1) {
            cout << "You win! Computer can't find a city." << endl;
            break;
        }

        string comp_city = cities[best_index].name;
        cout << "Computer: " << comp_city << endl;

        last_letter = toupper(comp_city.back());

        cities.erase(cities.begin() + best_index);
    }

    return 0;
}
