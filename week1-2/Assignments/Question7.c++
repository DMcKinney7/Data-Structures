#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;
struct bankAccount{
    int accountNumber;
    string fullName;
    string emailAddress;
    double accountBalance;
};
void menu();
void addAccount(vector<bankAccount>& accounts);
void printAccounts(vector<bankAccount>& accounts);

void sortAccounts(vector<bankAccount>& accounts);



bool comp(const bankAccount &a, const bankAccount &b) {
    return a.accountBalance < b.accountBalance;
}

int main()
{
    char userSelection;

    vector<bankAccount> account;

    do
    {
        menu();
        cin >> userSelection;
        
        switch (userSelection)
        {
            case '1':// Add Account
                addAccount(account);
                break;
                
            case '2':// Print Accounts  
                printAccounts(account);
                break;
                
            case '3':// Sort by balance 
                sortAccounts(account);       
                break;

            case '4':// Quit
                cout << "Exiting the program.\n" << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option.\n" << endl;
                userSelection = 0;
                break;
        }

    } while (userSelection != '4');
    return 0;
    
}

void menu(){
    cout << "Please select an option\n" << endl;
    cout << "\t1: Add Account" << endl;
    cout << "\t2: Print Accounts" << endl;
    cout << "\t3: Sort Accounts by Balance" << endl;
    cout << "\t4: Exit" << endl;
    cout << "\nSelect option: ";
}

void addAccount(vector<bankAccount>& accounts){
    int accountNumber;
    string fullName;
    string emailAddress;
    double accountBalance;
    cout << "Please enter the account number: " << endl;
    cin >> accountNumber;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // clear input buffer
    cout << "Please enter the full name: " << endl;
    getline(cin, fullName);
    cout << "Please enter the email address: " << endl;
    getline(cin, emailAddress);
    cout << "Please enter the account balance: " << endl;
    cin >> accountBalance;
    bankAccount newAccount = {accountNumber, fullName, emailAddress, accountBalance};
    accounts.push_back(newAccount);
}
void printAccounts(vector<bankAccount>& accounts){
     for (const bankAccount &v : accounts)
    {
        cout << "Account Number: " << v.accountNumber << "Full Name: " << v.fullName << "Email Address: " << v.emailAddress << ", Account Balance: " << fixed << setprecision(2) << v.accountBalance << endl;
    }
}
void sortAccounts(vector<bankAccount>& accounts){
    sort(accounts.begin(), accounts.end(), comp);
    for (const bankAccount &v : accounts)
    {
        cout << "Account Number: " << v.accountNumber << "Full Name: " << v.fullName << "Email Address: " << v.emailAddress << ", Account Balance: " << fixed << setprecision(2) << v.accountBalance << endl;
    }
}