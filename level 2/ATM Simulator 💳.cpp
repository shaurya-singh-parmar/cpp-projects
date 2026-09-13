/* This is a simple ATM simulator program
        made by ~~
                    Shaurya Singh */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Represents a bank account with a balance
struct Account {
    double balance = 0;
};

// Represents a customer with card number, PIN, and two accounts (savings and current)
struct Customer {
    string cardNumber;
    int pin;

    Account savings;
    Account current;
};


// Creates a new customer and adds them to the database
int createAccount(vector<Customer>& database) {

    string cardNumber;
    int pin;

    cout << "Enter your new card number: ";
    cin >> cardNumber;

    cout << "Enter your new PIN: ";
    cin >> pin;

    Customer newCustomer;

    newCustomer.cardNumber = cardNumber;
    newCustomer.pin = pin;

    database.push_back(newCustomer);

    cout << "Account created successfully!" << endl;

    return static_cast<int>(database.size() - 1);
}


// Checks whether the entered card number and PIN match a customer
int login(const vector<Customer>& database) {

    string cardNumber;
    int pin;

    cout << "Enter your card number: ";
    cin >> cardNumber;

    cout << "Enter your PIN: ";
    cin >> pin;

    for (size_t i = 0; i < database.size(); ++i) {

        if (database[i].cardNumber == cardNumber &&
            database[i].pin == pin) {

            cout << "Login successful!" << endl;

            return static_cast<int>(i);
        }
    }

    cout << "Invalid card number or PIN." << endl;

    return -1;
}

// Deposits money into the specified account type
void deposit(Customer& customer, double amount, const string& accountType) {

    if (amount <= 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    if (accountType == "savings") {

        customer.savings.balance += amount;

        cout << "Deposited ₹" << amount
             << " to Savings Account." << endl;

    } 
    else if (accountType == "current") {

        customer.current.balance += amount;

        cout << "Deposited ₹" << amount
             << " to Current Account." << endl;

    } 
    else {

        cout << "Invalid account type." << endl;
    }
}

// Withdraws money from the specified account type
void withdraw(Customer& customer, double amount, const string& accountType) {

    if (amount <= 0) {
        cout << "Invalid amount." << endl;
        return;
    }

    if (accountType == "savings") {

        if (customer.savings.balance >= amount) {

            customer.savings.balance -= amount;

            cout << "Withdrew ₹" << amount
                 << " from Savings Account." << endl;

        } 
        else {

            cout << "Insufficient funds in Savings Account." << endl;
        }

    } 
    else if (accountType == "current") {

        if (customer.current.balance >= amount) {

            customer.current.balance -= amount;

            cout << "Withdrew ₹" << amount
                 << " from Current Account." << endl;

        } 
        else {

            cout << "Insufficient funds in Current Account." << endl;
        }

    } 
    else {

        cout << "Invalid account type." << endl;
    }
}

// Displays the main menu and handles user choices
bool displayMenu(Customer& customer) {

    cout << "========================" << endl;
    cout << "=    ATM SIMULATOR 💳  =" << endl;
    cout << "========================" << endl;

    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Logout" << endl;

    int choice;
    double amount;
    string accountType;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {

        case 1:

            cout << "Savings Account Balance: ₹"
                 << customer.savings.balance << endl;

            cout << "Current Account Balance: ₹"
                 << customer.current.balance << endl;

            return true;


        case 2:

            cout << "Enter amount to deposit: ";
            cin >> amount;

            cout << "Enter account type (savings/current): ";
            cin >> accountType;

            deposit(customer, amount, accountType);

            return true;


        case 3:

            cout << "Enter amount to withdraw: ";
            cin >> amount;

            cout << "Enter account type (savings/current): ";
            cin >> accountType;

            withdraw(customer, amount, accountType);

            return true;


        case 4:

            cout << "Logging out..." << endl;

            return false;


        default:

            cout << "Invalid choice. Please try again." << endl;

            return true;
    }
}


int main() {

    vector<Customer> database;

    while (true) {

        cout << "========================" << endl;
        cout << "=    ATM SIMULATOR 💳  =" << endl;
        cout << "========================" << endl;

        cout << "1. Log In" << endl;
        cout << "2. Create Account" << endl;

        int choice;

        cout << "Enter your choice: ";
        cin >> choice;


        switch (choice) {

            case 1: {

                int customerIndex = login(database);

                if (customerIndex != -1) {

                    while (displayMenu(database[customerIndex])) {
                        cout << endl;
                    }
                }

                break;
            }


            case 2: {

                createAccount(database);

                break;
            }


            default:

                cout << "Invalid choice. Please try again." << endl;

                break;
        }

        cout << endl;
    }

    return 0;
}