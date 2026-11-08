#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;

struct Item
{
    string name;
    string productID;
    chrono::system_clock::time_point dateAdded;
    int quantity;
    double PricePerUnit;
};

void addItem(vector<Item>& inventory)
{
    Item newItem;
    cout <<"Enter item name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, newItem.name);
    cout <<"Enter product ID: ";
    getline(cin, newItem.productID);
    newItem.dateAdded = chrono::system_clock::now();
    cout <<"Enter quantity: ";
    cin >> newItem.quantity;
    cout <<"Enter price per unit: ";
    cin >> newItem.PricePerUnit;

    inventory.push_back(newItem);
    cout <<"Item added successfully!"<<endl;
}





int main()
{

vector<Item> inventory; // Vector to store inventory items

// Display menu
cout <<"================================"<<endl;
cout <<"|  Inventory Management System |"<<endl;
cout <<"================================"<<endl;

cout <<"|  Please select an option:    |"<<endl;
cout <<"| 1. Add Item                  |"<<endl;
cout <<"| 2. Remove Item               |"<<endl;
cout <<"| 3. View Inventory            |"<<endl;
cout <<"| 4. Search Item               |"<<endl;
cout <<"| 5. Sell Item                 |"<<endl;
cout <<"| 6. Exit                      |"<<endl;

int option;
cout <<"Enter your option: ";
cin >> option;

switch (option)
{
    case 1:
        addItem(inventory);
        break;
    case 2:
        // Code to remove item      
        break;
    case 3:
        // Code to view inventory
        break;
    case 4:
        // Code to search item
        break;
    case 5:
        // Code to sell item
        break;
    case 6:
        // Code to exit
        break;
    default:
        cout <<"Invalid option. Please try again."<<endl;
        break;
}

    return 0;
}