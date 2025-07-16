#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct User {
    string phone;
    string pin;
    double balance = 1000;
};

vector<User> users;
int currentUser = -1;

void registerUser() {

    string phone, pin;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Set a 4-digit PIN: ";
    cin >> pin;

    User newUser;
    newUser.phone = phone;
    newUser.pin = pin;
    newUser.balance = 1000;

    users.push_back(newUser);
    cout << "Registration successful!\n";
}

bool loginUser() {
    string phone, pin;
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter PIN: ";
    cin >> pin;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].phone == phone && users[i].pin == pin) {
            currentUser = i;
            cout << "Login successful!\n";
            return true;
        }
    }

    cout << "Wrong phone number or PIN.\n";
    return false;
}

void sendMoney() {
    string toPhone;
    double amount;
    cout << "Enter receiver's phone number: ";
    cin >> toPhone;
    cout << "Enter amount to send: ";
    cin >> amount;

    if (amount > users[currentUser].balance) {
        cout << "Not enough balance!\n";
        return;
    }

    for (int i = 0; i < users.size(); i++) {
        if (users[i].phone == toPhone) {
            users[currentUser].balance -= amount;
            users[i].balance += amount;
            cout << "Money sent successfully!\n";
            return;
        }
    }

    cout << "Receiver not found.\n";
}

void recharge() {
    double amount;
    cout << "Enter recharge amount: ";
    cin >> amount;

    if (amount > users[currentUser].balance) {
        cout << "Not enough balance!\n";
    } else {
        users[currentUser].balance -= amount;
        cout << "Recharge successful!\n";
    }
}

void payBill() {
    double bill;
    cout << "Enter bill amount: ";
    cin >> bill;

    if (bill > users[currentUser].balance) {
        cout << "Not enough balance to pay bill.\n";
    } else {
        users[currentUser].balance -= bill;
        cout << "Bill paid successfully!\n";
    }
}

void checkBalance() {
    cout << "Your current balance is: Tk " << users[currentUser].balance << endl;
}

void mainMenu() {
    int choice;
    while (true) {
        cout << "\n--- Main Menu ---\n";
        cout << "1. Send Money\n";
        cout << "2. Recharge\n";
        cout << "3. Pay Bill\n";
        cout << "4. Check Balance\n";
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) sendMoney();
        else if (choice == 2) recharge();
        else if (choice == 3) payBill();
        else if (choice == 4) checkBalance();
        else if (choice == 5) {
            currentUser = -1;
            break;
        } else cout << "Invalid option.\n";
    }
}

void initMenu() {
    int choice;
    while (true) {
        cout << "\n--- Welcome ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) registerUser();
        else if (choice == 2) {
            if (loginUser())
                mainMenu();
        }
        else if (choice == 3) {
            cout << "Thanks for using the app!\n";
            break;
        }
        else {
            cout << "Invalid option.\n";
        }
    }
}

int main() {
    initMenu();
    return 0;
}
