#include <iostream>
#include <string>
#include <vector>

struct Product {
    std::string name;
    int quantity;

    Product(const std::string& n, int q) : name(n), quantity(q) {}
};

std::vector<Product> inventory;

void addProduct() {
    std::string name;
    int quantity;

    std::cout << "Enter product name: ";
    std::cin.ignore(); // Ignore any leftover characters in the input buffer
    std::getline(std::cin, name);

    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    Product newProduct(name, quantity);
    inventory.push_back(newProduct);
    std::cout << "Product added successfully!\n";
}

void updateQuantity() {
    std::string name;
    int quantity;

    std::cout << "Enter product name to update quantity: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            std::cout << "Enter new quantity: ";
            std::cin >> quantity;
            inventory[i].quantity = quantity;
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Product not found!\n";
    } else {
        std::cout << "Quantity updated successfully!\n";
    }
}

void displayInventory() {
    std::cout << "Inventory:\n";
    for (size_t i = 0; i < inventory.size(); ++i) {
        std::cout << inventory[i].name << " - Quantity: " << inventory[i].quantity << "\n";
    }
}

void searchProduct() {
    std::string name;

    std::cout << "Enter product name to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool found = false;
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].name == name) {
            std::cout << "Product found! Quantity: " << inventory[i].quantity << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Product not found!\n";
    }
}

int main() {
    int choice;
    while (true) {
        std::cout << "\nOptions:\n";
        std::cout << "1. Add Product\n";
        std::cout << "2. Update Quantity\n";
        std::cout << "3. Display Inventory\n";
        std::cout << "4. Search Product\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                updateQuantity();
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                std::cout << "Exiting program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}

