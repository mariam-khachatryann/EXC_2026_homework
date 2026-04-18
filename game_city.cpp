#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct City {
    string name;
    long long population;
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
    vector<City> cities;
    string fileName = "worldcities(3).csv";
    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return 1;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        stringstream ss(line);
        string cell;
        vector<string> row;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        if (row.size() >= 8) {
            City c;
            c.name = row[1]; 
            try {
                c.population = stoll(row.back());
            } catch (...) {
                c.population = 0;
            }
            cities.push_back(c);
        }
    }
    file.close();

    cout << "--- Welcome to the City Game! ---" << endl;
    cout << "Total cities loaded: " << cities.size() << endl;
    cout << "(Type 'exit' or 'quit' to surrender)" << endl;
    cout << "(Type 'help' if you can't find a city)" << endl;

    string start_city = "Yerevan";
    cout << "\nComputer starts: " << start_city << endl;

    char last_letter = toupper(start_city.back());
    exists(start_city, cities);

    string input_city;
    while (true) {
        cout << "\nYour turn! Enter a city starting with '" << last_letter << "': ";
        getline(cin, input_city);

        if (input_city.empty()) continue;

        if (input_city == "exit" || input_city == "quit" || input_city == "EXIT" || input_city == "QUIT") {
            cout << "\nYou surrendered! Game Over. Better luck next time!" << endl;
            break;
        }

        if (input_city == "help" || input_city == "Help" || input_city == "HELP") {
            int best_index = -1;
            long long max_population = -1;

            for (int i = 0; i < cities.size(); i++) {
                if (toupper(cities[i].name[0]) == last_letter) {
                    if (cities[i].population > max_population) {
                        max_population = cities[i].population;
                        best_index = i;
                    }
                }
            }

            if (best_index != -1) {
                string suggested_city = cities[best_index].name;
                cout << "\nI'll help you out! Let's go with: " << suggested_city << endl;
                
                last_letter = toupper(suggested_city.back());
                cities.erase(cities.begin() + best_index);
                
            } else {
                cout << "\nI can't find cities too with '" << last_letter << "'." << endl;
            }
            continue; 
        }

        input_city[0] = toupper(input_city[0]);

        if (toupper(input_city[0]) != last_letter) {
            cout << "Invalid starting letter! Please try again." << endl;
            continue;
        }

        if (!exists(input_city, cities)) {
            bool suggestionFound = false;
            for (int i = 0; i < cities.size(); i++) {
                string cityName = cities[i].name;
                
                if (abs((int)input_city.length() - (int)cityName.length()) <= 1) {
                    int matchCount = 0;
                    int minLen = min((int)input_city.length(), (int)cityName.length());
                    
                    for (int j = 0; j < minLen; j++) {
                        if (toupper(input_city[j]) == toupper(cityName[j])) {
                            matchCount++;
                        }
                    }
                    
                    if (matchCount >= (int)input_city.length() - 2 && matchCount > 2) {
                        cout << "City not found. Did you mean '" << cityName << "'? (Please re-type it accurately)" << endl;
                        suggestionFound = true;
                        break; 
                    }
                }
            }
            
            if (!suggestionFound) {
                cout << "City not found or already mentioned. Try another one!" << endl;
            }
            continue;
        }

        last_letter = toupper(input_city.back());

        int best_index = -1;
        long long max_population = -1;

        for (int i = 0; i < cities.size(); i++) {
            if (toupper(cities[i].name[0]) == last_letter) {
                if (cities[i].population > max_population) {
                    max_population = cities[i].population;
                    best_index = i;
                }
            }
        }

        if (best_index == -1) {
            cout << "\nCongratulations! You win! The computer is out of cities." << endl;
            break;
        }

        string comp_city = cities[best_index].name;
        cout << "Computer: " << comp_city << endl;

        last_letter = toupper(comp_city.back());
        cities.erase(cities.begin() + best_index);
    }

    return 0;
}