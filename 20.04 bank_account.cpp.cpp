#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BankAccount {
private:
    double balance = 0;
    vector<pair<string, double>> history;
    bool deposit_limit = false;
    double withdraw_limit = 400.0;

public:

    BankAccount() {
        balance = 0;
        deposit_limit = false;
        withdraw_limit = 400.0;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!\n";
            return;
        }
        if (balance >= 10000) {
            cout << "Your balance is already 10000, limit is over." << endl; 
            cout << "Type 'Exit', start new section to add more balance!" << endl;
            deposit_limit = true;
        }
        if (!deposit_limit) {
            balance += amount;
            history.push_back({"Balance added", amount});
        }
    }

    void withdraw(double amount) {
        if (balance < amount) {
            cout << "You don't have enough balance!\n";
        }
        else if (withdraw_limit < amount) {
            cout << "Limit exceeded! Start new session.\n";
        }
        else {
            withdraw_limit -= amount;
            balance -= amount;
            history.push_back({"Balance withdrawn", amount});
        }
    }

    void show_balance() const {
        cout << "-----------------------\n";
        cout << "Balance: " << balance << endl;
        cout << "-----------------------\n";
    }

    void show_history() const {
        cout << "-----------------------\n";
        cout << "Transaction history:\n";
        for (const auto& x : history) {
            cout << x.first << ": " << x.second << endl;
        }
        cout << "Current Balance: " << balance << endl;
        cout << "-----------------------\n";
    }
};

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

int main() {
    string start;
    cout << "If you want to start input 'Enter': ";
    cin >> start;

    start = toLower(start);
    if (start != "enter") {
        cout << "Session not started.\n";
        return 0;
    }

    BankAccount ba;

    while (true) {
        string action;
        cout << "\nEnter action (deposit, withdraw, balance, history, exit): ";
        cin >> action;

        action = toLower(action);

        if (action == "deposit") {
            double num;
            cout << "Enter deposit amount: ";
            cin >> num;

            if (cin.fail()) {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                continue;
            }

            ba.deposit(num);
        }
        else if (action == "withdraw") {
            double num;
            cout << "Enter withdraw amount: ";
            cin >> num;

            if (cin.fail()) {
                cout << "Invalid input! Please enter a number.\n";
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            ba.withdraw(num);
        }
        else if (action == "history") {
            ba.show_history();
        }
        else if (action == "balance") {
            ba.show_balance();
        }
        else if (action == "exit") {
            cout << "Starting new session...\n";
            ba = BankAccount(); 
            continue;
        }
        else {
            cout << "Please enter a valid command!\n";
        }
    }

    return 0;
}