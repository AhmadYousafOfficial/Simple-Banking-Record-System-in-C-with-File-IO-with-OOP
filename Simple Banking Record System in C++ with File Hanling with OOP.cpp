#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// Represents a single bank account record
class Account {
public:
    int    accountNumber;
    string firstName;
    string lastName;
    double balance;

    Account()
      : accountNumber(0), firstName(""), lastName(""), balance(0.0)
    {}

    // Write this account’s data to the given output file stream
    void writeToFile(ofstream &file) const {
        file << accountNumber << ' '
             << firstName     << ' '
             << lastName      << ' '
             << fixed << setprecision(2) << balance
             << '\n';
    }

    // Read an account’s data from the given input file stream;
    // returns true on success, false at EOF or on failure
    bool readFromFile(ifstream &file) {
        return bool(file >> accountNumber
                         >> firstName
                         >> lastName
                         >> balance);
    }

    // Print this account’s details to the console
    void display() const {
        cout << setprecision(2) << showpoint << fixed;
        cout << "Account No: " << accountNumber << "\n"
             << "Name:       " << firstName << " " << lastName << "\n"
             << "Balance:    $"  << balance << "\n"
             << "--------------------------------\n";
    }
};

// Manages all accounts and file operations
class Bank {
private:
    const char *filename;  // use a plain C-string so older compilers like Dev-C++ accept it

public:
    // initialize filename in constructor
    Bank() : filename("Bank Records.txt") {}

    void addRecord() {
        Account acc;
        cout << "Enter Account Number: ";
        cin  >> acc.accountNumber;
        cout << "Enter First Name:     ";
        cin  >> acc.firstName;
        cout << "Enter Last Name:      ";
        cin  >> acc.lastName;
        cout << "Enter Balance:        ";
        cin  >> acc.balance;

        ofstream file(filename, ios::app);
        if (!file) {
            cerr << "Error: cannot open file for writing!\n";
            return;
        }
        acc.writeToFile(file);
        cout << "Record added successfully!\n\n";
    }

    void displayRecords() const {
        ifstream file(filename);
        if (!file) {
            cerr << "Error: cannot open file or no records exist.\n\n";
            return;
        }

        cout << "\n--- All Bank Records ---\n";
        cout << "--------------------------------\n";
        Account acc;
        while (acc.readFromFile(file)) {
            acc.display();
        }
        cout << '\n';
    }

    void searchRecord() const {
        cout << "Enter Account Number to search: ";
        int target;
        cin  >> target;

        ifstream file(filename);
        if (!file) {
            cerr << "Error: cannot open file or no records exist.\n\n";
            return;
        }

        Account acc;
        bool found = false;
        while (acc.readFromFile(file)) {
            if (acc.accountNumber == target) {
                cout << "\n--- Record Found ---\n";
                cout << "--------------------------------\n";
                acc.display();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Record not found!\n\n";
        }
    }

    void menu() {
        int choice;
        do {
            cout << "=== Bank Record System (OOP) ===\n"
                 << "1. Add a record\n"
                 << "2. Display all records\n"
                 << "3. Search for a record\n"
                 << "4. Quit\n"
                 << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1: addRecord();      break;
                case 2: displayRecords(); break;
                case 3: searchRecord();   break;
                case 4: cout << "Goodbye!\n"; break;
                default:
                    cout << "Invalid choice. Please enter 1–4.\n\n";
            }
        } while (choice != 4);
    }
};

int main() {
    Bank bank;
    bank.menu();
    return 0;
}

