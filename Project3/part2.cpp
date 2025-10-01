#include <iostream>
#include "varList.h"
using namespace std;

int main() {
    VarList<int> intList;
    char op;
    int value;

    while (true) {
        cout << "\nEnter operation [A/R/Q]: ";
        cin >> op;
        if (op == 'Q' || op == 'q') {
            break;
        } else if (op == 'A' || op == 'a') {
            cout << "Enter a value                : ";
            cin >> value;
            intList.addValue(value);
        } else if (op == 'R' || op == 'r') {
            cout << "Enter a value                : ";
            cin >> value;
            intList.removeValue(value);
        } else {
            cout << "Invalid operation. Please enter A, R, or Q.\n";
            continue;
        }
        cout << "Current values stored in the list: ";
        intList.printList();
    }
    cout << "Program ended.\n";
    return 0;
}