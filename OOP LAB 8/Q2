#include <iostream>
using namespace std;

class BankAccount;

void sendMoney(BankAccount &sender, BankAccount &receiver, double amount);

class BankAccount {
private:
    int accNumber;
    double currentBalance;

public:
    BankAccount(int number, double balance)
        : accNumber(number), currentBalance(balance) {}

    friend class BankManager;
    friend void sendMoney(BankAccount &sender, BankAccount &receiver, double amount);
};

class BankManager {
public:
    void addFunds(BankAccount &acc, double amount) {
        if (amount > 0) {
            acc.currentBalance += amount;
            cout << "Added $" << amount << " to Account #" << acc.accNumber << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    void withdrawFunds(BankAccount &acc, double amount) {
        if (amount > 0 && amount <= acc.currentBalance) {
            acc.currentBalance -= amount;
            cout << "Withdrew $" << amount << " from Account #" << acc.accNumber << endl;
        } else {
            cout << "Invalid withdrawal: Insufficient balance or amount is not valid." << endl;
        }
    }

    void showAccount(const BankAccount &acc) {
        cout << "Account #" << acc.accNumber
             << " | Balance: $" << acc.currentBalance << endl;
    }
};

void sendMoney(BankAccount &sender, BankAccount &receiver, double amount) {
    if (amount > 0 && sender.currentBalance >= amount) {
        sender.currentBalance -= amount;
        receiver.currentBalance += amount;
        cout << "Successfully transferred $" << amount
             << " from Account #" << sender.accNumber
             << " to Account #" << receiver.accNumber << endl;
    } else {
        cout << "Transfer failed: Not enough balance or invalid amount." << endl;
    }
}

int main() {
    BankAccount johnsAccount(101, 1000.0);
    BankAccount annasAccount(102, 500.0);

    BankManager manager;

    cout << "=== Initial Account Info ===" << endl;
    manager.showAccount(johnsAccount);
    manager.showAccount(annasAccount);

    manager.addFunds(johnsAccount, 200.0);
    manager.withdrawFunds(annasAccount, 100.0);
    sendMoney(johnsAccount, annasAccount, 300.0);

    cout << "\n=== Final Account Info ===" << endl;
    manager.showAccount(johnsAccount);
    manager.showAccount(annasAccount);

    return 0;
}
