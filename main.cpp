/*
 * Bank Name: Nikita Bank of Loni
 * Project Title: Bank Account Management System Using C++
 * Course: Object-Oriented Programming (OOP)
 */

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// ==========================================
// Class Definition: BankAccount
// ==========================================
class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;
    string atmCardNumber;
    string atmPin;

public:
    BankAccount() {
        accountNumber = "";
        accountHolder = "";
        balance = 0.0;
        atmCardNumber = "";
        atmPin = "";
    }

    BankAccount(string accNum, string name, double initialBalance, string pin, string cardNumber = "") {
        accountNumber = accNum;
        accountHolder = name;
        balance = (initialBalance >= 0) ? initialBalance : 0.0;
        atmPin = pin;
        if (cardNumber.empty()) {
            atmCardNumber = generateDemoATMCardNumber();
        } else {
            atmCardNumber = cardNumber;
        }
    }

    static string generateDemoATMCardNumber() {
        static int cardCounter = 1001;
        string numStr = to_string(cardCounter++);
        while (numStr.length() < 4) numStr = "0" + numStr;
        return "4567 8912 3456 " + numStr;
    }

    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }
    string getAtmCardNumber() const { return atmCardNumber; }

    bool verifyPin(string inputPin) const {
        return (inputPin == atmPin);
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "\n[Error] Deposit amount must be greater than zero.\n";
            return;
        }
        balance += amount;
        cout << "\n[Success] Money Deposited Successfully!\n";
        cout << "Deposited Amount: $" << fixed << setprecision(2) << amount << "\n";
        cout << "Updated Balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be greater than zero.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient Balance!");
        }

        balance -= amount;
        cout << "\n[Success] Withdrawal Successful!\n";
        cout << "Withdrawn Amount: $" << fixed << setprecision(2) << amount << "\n";
        cout << "Remaining Balance: $" << balance << "\n";
    }

    void checkBalance() const {
        cout << "\n----------------------------------------\n";
        cout << " Current Balance: $" << fixed << setprecision(2) << balance << "\n";
        cout << "----------------------------------------\n";
    }

    void displayDetails() const {
        cout << "\n----------------------------------------\n";
        cout << "          ACCOUNT DETAILS               \n";
        cout << "----------------------------------------\n";
        cout << " Bank Name      : Nikita Bank of Loni   \n";
        cout << " Account Number : " << accountNumber << "\n";
        cout << " Account Holder : " << accountHolder << "\n";
        cout << " Current Balance: $" << fixed << setprecision(2) << balance << "\n";
        cout << " ATM Card Number: " << atmCardNumber << "\n";
        cout << " ATM Card Status: Active\n";
        cout << "----------------------------------------\n";
    }

    void displayATMCard() const {
        cout << "\n----------------------------------------\n";
        cout << "             DEMO ATM CARD              \n";
        cout << "----------------------------------------\n";
        cout << " NIKITA BANK OF LONI                    \n";
        cout << "                                        \n";
        cout << " Card Holder : " << accountHolder << "\n";
        cout << " Card Number : " << atmCardNumber << "\n";
        cout << " Account No  : " << accountNumber << "\n";
        cout << " Valid Thru  : 12/30                    \n";
        cout << " Status      : ACTIVE                   \n";
        cout << "----------------------------------------\n";
    }
};

void clearInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int findAccountIndex(const vector<BankAccount>& accounts, const string& accNum) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

int main() {
    vector<BankAccount> bankAccounts;
    int activeAccountIdx = -1;
    int choice;

    do {
        cout << "\n===== NIKITA BANK OF LONI =====\n";
        cout << "1. Create Account\n";
        cout << "2. Access Existing Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Check Balance\n";
        cout << "6. Display Account Details\n";
        cout << "7. ATM Card\n";
        cout << "8. Exit\n";
        cout << "Enter your choice (1-8): ";

        if (!(cin >> choice)) {
            cout << "\n[Error] Invalid input! Please enter a number between 1 and 8.\n";
            clearInvalidInput();
            continue;
        }

        switch (choice) {
        case 1: {
            string accNum, name, pin;
            double initBalance;

            cout << "\n--- CREATE NEW ACCOUNT ---\n";
            cout << "Enter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            if (accNum.empty()) {
                cout << "\n[Error] Account number cannot be empty!\n";
                break;
            }

            if (findAccountIndex(bankAccounts, accNum) != -1) {
                cout << "\n[Error] Account Number Already Exists!\n";
                break;
            }

            cout << "Enter Account Holder Name: ";
            getline(cin, name);
            if (name.empty()) {
                cout << "\n[Error] Account holder name cannot be empty!\n";
                break;
            }

            cout << "Enter Initial Balance ($): ";
            while (!(cin >> initBalance) || initBalance < 0) {
                cout << "[Error] Invalid amount. Enter positive initial balance ($): ";
                clearInvalidInput();
            }

            cout << "Enter 4-Digit ATM PIN: ";
            cin >> ws;
            getline(cin, pin);

            BankAccount newAccount(accNum, name, initBalance, pin);
            bankAccounts.push_back(newAccount);
            activeAccountIdx = bankAccounts.size() - 1;

            cout << "\n[Success] Account Created Successfully!\n";
            cout << "Bank: Nikita Bank of Loni\n";
            cout << "Assigned ATM Card Number: " << newAccount.getAtmCardNumber() << "\n";
            newAccount.displayDetails();
            break;
        }

        case 2: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist in the system yet. Please create an account first.\n";
                break;
            }
            string accNum;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
            } else {
                activeAccountIdx = idx;
                cout << "\n[Success] Account Loaded Successfully!\n";
                cout << "Welcome to Nikita Bank of Loni, " << bankAccounts[idx].getAccountHolder() << "!\n";
                cout << "Current Balance: $" << fixed << setprecision(2) << bankAccounts[idx].getBalance() << "\n";
                cout << "ATM Card Number: " << bankAccounts[idx].getAtmCardNumber() << "\n";
            }
            break;
        }

        case 3: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist yet! Please create an account first.\n";
                break;
            }

            string accNum;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
                break;
            }

            double amount;
            cout << "Enter Amount to Deposit ($): ";
            if (cin >> amount) {
                bankAccounts[idx].deposit(amount);
                activeAccountIdx = idx;
            } else {
                cout << "\n[Error] Invalid deposit amount.\n";
                clearInvalidInput();
            }
            break;
        }

        case 4: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist yet! Please create an account first.\n";
                break;
            }

            string accNum, pin;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
                break;
            }

            cout << "Enter ATM PIN: ";
            getline(cin, pin);

            if (!bankAccounts[idx].verifyPin(pin)) {
                cout << "\n[Error] Invalid PIN!\n";
                break;
            }
            cout << "[Success] PIN Verified Successfully!\n";

            double amount;
            cout << "Enter Amount to Withdraw ($): ";
            if (cin >> amount) {
                try {
                    bankAccounts[idx].withdraw(amount);
                    activeAccountIdx = idx;
                } catch (const invalid_argument& e) {
                    cout << "\n[Exception Caught] Invalid Amount: " << e.what() << "\n";
                } catch (const runtime_error& e) {
                    cout << "\n[Exception Caught] " << e.what() << "\n";
                } catch (...) {
                    cout << "\n[Exception Caught] An unexpected error occurred during withdrawal.\n";
                }
            } else {
                cout << "\n[Error] Invalid withdrawal amount.\n";
                clearInvalidInput();
            }
            break;
        }

        case 5: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist yet! Please create an account first.\n";
                break;
            }
            string accNum;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
            } else {
                activeAccountIdx = idx;
                cout << "\nAccount Holder : " << bankAccounts[idx].getAccountHolder() << "\n";
                bankAccounts[idx].checkBalance();
            }
            break;
        }

        case 6: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist yet! Please create an account first.\n";
                break;
            }
            string accNum;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
            } else {
                activeAccountIdx = idx;
                bankAccounts[idx].displayDetails();
            }
            break;
        }

        case 7: {
            if (bankAccounts.empty()) {
                cout << "\n[Error] No accounts exist yet! Please create an account first.\n";
                break;
            }
            string accNum, pin;
            cout << "\nEnter Account Number: ";
            cin >> ws;
            getline(cin, accNum);

            int idx = findAccountIndex(bankAccounts, accNum);
            if (idx == -1) {
                cout << "\n[Error] Account Not Found!\n";
                break;
            }

            cout << "Enter ATM PIN: ";
            getline(cin, pin);

            if (!bankAccounts[idx].verifyPin(pin)) {
                cout << "\n[Error] Invalid PIN!\n";
                break;
            }

            cout << "[Success] PIN Verified Successfully!\n";
            activeAccountIdx = idx;
            bankAccounts[idx].displayATMCard();
            break;
        }

        case 8:
            cout << "\nThank you for using Nikita Bank of Loni. Goodbye!\n";
            break;

        default:
            cout << "\n[Error] Invalid choice! Please select an option from 1 to 8.\n";
            break;
        }

    } while (choice != 8);

    return 0;
}
