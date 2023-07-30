#include <iostream>
#include <vector>
#include <string>

// Define classes
class Customer {
public:
    Customer(const std::string& name, const std::string& address)
        : name(name), address(address) {}

    std::string getName() const { return name; }
    std::string getAddress() const { return address; }

private:
    std::string name;
    std::string address;
};

class Account {
public:
    Account(int accountNumber, double balance, Customer customer)
        : accountNumber(accountNumber), balance(balance), customer(customer) {}

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
    Customer getCustomer() const { return customer; }

    void deposit(double amount) { balance += amount; }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            std::cout << "Insufficient funds!" << std::endl;
        }
    }

private:
    int accountNumber;
    double balance;
    Customer customer;
};

// Function prototypes
void addCustomer();
void createAccount();
void deposit();
void withdraw();
void displayAccounts();

// Global variables
std::vector<Customer> customers;
std::vector<Account> accounts;

int main() {
    int choice;

    while (true) {
        std::cout << "Bank Management System" << std::endl;
        std::cout << "1. Add Customer" << std::endl;
        std::cout << "2. Create Account" << std::endl;
        std::cout << "3. Deposit" << std::endl;
        std::cout << "4. Withdraw" << std::endl;
        std::cout << "5. Display Accounts" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addCustomer();
                break;
            case 2:
                createAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                displayAccounts();
                break;
            case 6:
                std::cout << "Exiting... Thank you!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void addCustomer() {
    std::string name, address;
    std::cout << "Enter customer name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter customer address: ";
    std::getline(std::cin, address);

    Customer newCustomer(name, address);
    customers.push_back(newCustomer);
    std::cout << "Customer added successfully!" << std::endl;
}

void createAccount() {
    if (customers.empty()) {
        std::cout << "No customers found. Please add a customer first." << std::endl;
        return;
    }

    int customerIndex, accountNumber;
    double initialBalance;
    std::cout << "Select customer by index (0 - " << customers.size() - 1 << "): ";
    std::cin >> customerIndex;

    if (customerIndex < 0 || customerIndex >= customers.size()) {
        std::cout << "Invalid customer index." << std::endl;
        return;
    }

    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;

    Account newAccount(accountNumber, initialBalance, customers[customerIndex]);
    accounts.push_back(newAccount);
    std::cout << "Account created successfully!" << std::endl;
}

void deposit() {
    if (accounts.empty()) {
        std::cout << "No accounts found. Please create an account first." << std::endl;
        return;
    }

    int accountIndex;
    double amount;
    std::cout << "Select account by index (0 - " << accounts.size() - 1 << "): ";
    std::cin >> accountIndex;

    if (accountIndex < 0 || accountIndex >= accounts.size()) {
        std::cout << "Invalid account index." << std::endl;
        return;
    }

    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    accounts[accountIndex].deposit(amount);
    std::cout << "Deposit successful. New balance: " << accounts[accountIndex].getBalance() << std::endl;
}

void withdraw() {
    if (accounts.empty()) {
        std::cout << "No accounts found. Please create an account first." << std::endl;
        return;
    }

    int accountIndex;
    double amount;
    std::cout << "Select account by index (0 - " << accounts.size() - 1 << "): ";
    std::cin >> accountIndex;

    if (accountIndex < 0 || accountIndex >= accounts.size()) {
        std::cout << "Invalid account index." << std::endl;
        return;
    }

    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;

    accounts[accountIndex].withdraw(amount);
    std::cout << "Withdrawal successful. New balance: " << accounts[accountIndex].getBalance() << std::endl;
}

void displayAccounts() {
    if (accounts.empty()) {
        std::cout << "No accounts found." << std::endl;
        return;
    }

    std::cout << "Accounts:" << std::endl;
    for (std::vector<Account>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        std::cout << "Account Number: " << it->getAccountNumber() << std::endl;
        std::cout << "Customer Name: " << it->getCustomer().getName() << std::endl;
        std::cout << "Balance: " << it->getBalance() << std::endl;
        std::cout << "--------------------------" << std::endl;
    }
}



