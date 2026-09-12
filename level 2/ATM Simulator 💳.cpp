#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Account {
    double balance = 0;
};

struct Customer {
    string cardNumber;
    int pin;

    Account savings;
    Account current;
};

void deposit(Customer& customer, double amount, const string& accountType) {
    if (accountType == "savings") {
        customer.savings.balance += amount;
        cout << "Deposited ₹" << amount << " to Savings Account." << endl;
    } else if (accountType == "current") {
        customer.current.balance += amount;
        cout << "Deposited ₹" << amount << " to Current Account." << endl;
    } else {
        cout << "Invalid account type." << endl;
    }
}

void withdraw(Customer& customer, double amount, const string& accountType) {
   
    if (amount <0) {
        cout << "Invalid amount." << endl;
        return;
    }
   
    if (accountType == "savings") {
        if (customer.savings.balance >= amount) {
            customer.savings.balance -= amount;
            cout << "Withdrew ₹" << amount << " from Savings Account." << endl;
        } else {
            cout << "Insufficient funds in Savings Account." << endl;
        }
    } else if (accountType == "current") {
        if (customer.current.balance >= amount) {
            customer.current.balance -= amount;
            cout << "Withdrew ₹" << amount << " from Current Account." << endl;
        } else {
            cout << "Insufficient funds in Current Account." << endl;
        }
    } else {
        cout << "Invalid account type." << endl;
    }
    
}

void displayMenu() {
    cout << "========================" << endl;
    cout << "=    ATM SIMULATOR 💳  =" << endl;
    cout << "========================" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Exit" << endl;
}

int main() {

    cout << "========================" << endl;
    cout << "=    ATM SIMULATOR 💳  =" << endl;
    cout << "========================" << endl;

    vector<Customer> database;

    Customer customer;

    cout << "Enter your Card Number: ";
    cin >> customer.cardNumber;

    cout << "Enter your PIN: ";
    cin >> customer.pin;

    database.push_back(customer);

    displayMenu();

    return 0;

}