#include <iostream>
#include <string>

using namespace std;

const int n = 5; // constant check size of 5

// Struct to represent a check
struct check {
    int checknum;
    string checkmemo;
    int checkamount; // Change the data type to int
};

// Class to represent a checkbook
class checkbook {
private:
    float balance;
    check checks[n];
    float lastdeposit;
    int numofchecks;
    const int checklimit;

public:
    // Default constructor
    checkbook() : balance(0), lastdeposit(0), numofchecks(0), checklimit(n) {}

    // Constructor with initial balance
    checkbook(float initialbalance) : balance(initialbalance), lastdeposit(0), numofchecks(0), checklimit(n) {}

    // Function to deposit money into the checkbook
    void deposit(float amount) {
        balance += amount;
        lastdeposit = amount;
    }

    // Function to display the check history
    void displaycheck() {
        cout << "Check history is:" << endl;
        for (int i = numofchecks - 1; i >= 0; --i) {
            cout << "Check number: " << checks[i].checknum << ", Memo: " << checks[i].checkmemo
                 << ", Amount: " << checks[i].checkamount << endl;
        }
    }

    // Function to write a check
    bool writecheck(float amount) {
        if (amount <= balance) {
            cout << "Please enter the information for the check:" << endl;
            cout << "Memo: ";
            cin >> checks[numofchecks].checkmemo;
            checks[numofchecks].checknum = numofchecks + 1;
            checks[numofchecks].checkamount = static_cast<int>(amount); // Convert to integer
            balance -= amount;
            lastdeposit = 0;
            numofchecks++;
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    // Create a checkbook object
    checkbook mycheckbook;

    // Deposit money and display check history
    mycheckbook.deposit(1000);
    mycheckbook.displaycheck();

    // Write a check and display updated check history
    float amounttowrite = 300;
    if (mycheckbook.writecheck(amounttowrite)) {
        cout << "Check has been written successfully. Good job!" << endl;
    } else {
        cout << "You're broke!!! You don't have the money to write that check." << endl;
    }

    mycheckbook.displaycheck();

    // Create another checkbook object
    checkbook anothermycheckbook;

    // Deposit money and display check history
    anothermycheckbook.deposit(500);
    anothermycheckbook.displaycheck();

    // Write a check and display updated check history
    float anotheramounttowrite = 700;
    if (anothermycheckbook.writecheck(anotheramounttowrite)) {
        cout << "Check has been written successfully. Good job!" << endl;
    } else {
        cout << "You're broke!!! You don't have the money to write that check." << endl;
    }

    anothermycheckbook.displaycheck();

    return 0;
}
