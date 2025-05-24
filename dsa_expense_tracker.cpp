#include <iostream>
#include <string>
using namespace std;

// FIRST NODE
struct DescriptionNode {
    string description;
};

// SECOND NODE
struct AmountNode {
    float amount;
};

// MASTER NODE
struct Expense {
    DescriptionNode *descNode;
    AmountNode *amtNode;
    Expense *next;
};

class ExpenseTracker {
private:
    Expense *head;

public:
    ExpenseTracker() {
        head = NULL;
    }

    void addExpense(string desc, float amt) {
        DescriptionNode *newDesc = new DescriptionNode{desc};
        AmountNode *newAmt = new AmountNode{amt};
        Expense *newExpense = new Expense{newDesc, newAmt, NULL};

        if (head == NULL) {
            head = newExpense;
        } else {
            Expense *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newExpense;
        }
        cout << "Expense added successfully:" << endl;
    }

    void viewExpenses() {
        if (head == NULL) {
            cout << "No expenses to display:" << endl;
            return;
        }

        Expense *temp = head;
        int count = 1;
        cout << endl << " All Expenses " << endl;
        while (temp != NULL) {
            cout << count++ << ". " << temp->descNode->description << "  $" << temp->amtNode->amount << endl;
            temp = temp->next;
        }
    }

    void generateReport() {
        float total = 0;
        Expense *temp = head;
        while (temp != NULL) {
            total += temp->amtNode->amount;
            temp = temp->next;
        }
        cout << endl << "Total Expense: $" << total << endl;
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    string desc;
    float amt;

    do {
        cout << endl << " Expense Tracking App " << endl;
        cout << "1: Add Expense" << endl;
        cout << "2: View All Expenses" << endl;
        cout << "3: Generate Report" << endl;
        cout << "4: Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter description: ";
                getline(cin, desc);
                cout << "Enter amount: ";
                cin >> amt;
                tracker.addExpense(desc, amt);
                break;
            case 2:
                tracker.viewExpenses();
                break;
            case 3:
                tracker.generateReport();
                break;
            case 4:
                cout << " Exiting program " << endl;
                break;
            default:
                cout << "Invalid Choice. Try Again." << endl;
        }
    } while (choice != 4);
    return 0;
}
