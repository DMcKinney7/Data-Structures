#include <iostream>
using namespace std;

int main()
{
    char UserSelection;
    
    cout << "1: New Account." << endl;
    cout << "2: Edit Existing Account." << endl;
    cout << "3. Erase Account." << endl;
    cout << "E. Exit" << endl;
    cout << "Please Enter Your Selection" << endl;

    cin >> UserSelection;

    switch(UserSelection) {
        
        case '1':
            newAccount();
            break;

        case '2':
            editAccount();
            break;

        case '3':
            eraseAccount();
            break;

        case 'E' || 'e':
            return 0;
            break;

        default:
            cout << "Unknown Selection!" << endl;
            menu();
            break;
    }
}

int newAccount() {
    return 0;
}
int editAccount() {
    return 0;
}
int eraseAccount() {
    return 0;
}
int menu() {
    return 0;
}
