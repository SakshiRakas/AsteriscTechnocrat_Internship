#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a menu item
struct MenuItem {
    string name;
    double price;
};

// Function to display the menu
void displayMenu(const vector<MenuItem>& menu) {
    cout << "---- Menu ----\n";
    for (vector<MenuItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
        cout << it->name << " - $" << it->price << "\n";
    }
    cout << "---------------\n";
}

// Function to take the order
void takeOrder(const vector<MenuItem>& menu, vector<MenuItem>& order) {
    cout << "Enter item name to add to the order (or 'done' to finish):\n";
    string itemName;
    while (true) {
        cin >> itemName;
        if (itemName == "done") {
            break;
        }

        bool itemFound = false;
        for (vector<MenuItem>::const_iterator it = menu.begin(); it != menu.end(); ++it) {
            if (it->name == itemName) {
                order.push_back(*it);
                itemFound = true;
                break;
            }
        }

        if (!itemFound) {
            cout << "Item not found. Please enter a valid item name.\n";
        }
    }
}

// Function to generate the bill
void generateBill(const vector<MenuItem>& order) {
    cout << "---- Bill ----\n";
    double totalCost = 0.0;
    for (vector<MenuItem>::const_iterator it = order.begin(); it != order.end(); ++it) {
        cout << it->name << " - $" << it->price << "\n";
        totalCost += it->price;
    }
    cout << "Total: $" << totalCost << "\n";
    cout << "--------------\n";
}

int main() {
    vector<MenuItem> menu;
    menu.push_back(MenuItem{"Coffee", 2.5});
    menu.push_back(MenuItem{"Tea", 2.0});
    menu.push_back(MenuItem{"Sandwich", 5.0});
    menu.push_back(MenuItem{"Cake", 3.5});
    // Add more items to the menu if needed

    vector<MenuItem> order;

    int choice;
    do {
        cout << "Welcome to the Cafe Management System\n";
        cout << "1. Display Menu\n";
        cout << "2. Take Order\n";
        cout << "3. Generate Bill\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayMenu(menu);
                break;
            case 2:
                takeOrder(menu, order);
                break;
            case 3:
                if (!order.empty()) {
                    generateBill(order);
                } else {
                    cout << "Order is empty. Please take the order first.\n";
                }
                break;
            case 4:
                cout << "Exiting the Cafe Management System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}

