#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
void menu();


int main()
{
    struct backAccount{
    int accountNumber;
    string fullName;
    string emailAddress;
    double accountBalance;
    };
    char UserSelection;

    vector<backAccount> accounts;

    do
    {
        menu();
        cin >> UserSelection;
        
        switch (UserSelection)
        {
            case '1':// Add Account
                break;
                
            case '2':// Print Accounts  
                break;
                
            case '3':// Sort by balance        
                break;

            case '4':// Quit
                cout << "Exiting the program.\n" << endl;
                break;

            default:
                cout << "Invalid choice. Please select a valid option.\n" << endl;
                UserSelection = 0;
                break;
        }

    } while (UserSelection != '4');
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
/*
Scope
Question 7:  Bank Accounts

Design and implement a C++ program that reads a number of bank accounts entered by the user and then prints them sorted based on their account balance. The bank account information is entered as a set of four fields (pieces of information) as shown below:

Account Number (integer)

Customer full name (string)

Customer email (string)

Account Balance (double)

The program is expected to read the number of the accounts from the user and then the account information and then prints the records in the format shown below, sorted in decreasing order based on the account balance:

Account Number :  1201077

Name                     :  Jonathan I. Maletic

Email                      :  jmaletic@ksu.edu

Balance                   : 10,000.17

-------------------------------------

Note: The records are entered in the following format (4 lines for each account):

 

First Line is the account number

Second Line is full name

Third line is email

Forth line is the available balance

 

Example

(data entered by the user)
	

Output:

1201077

Jonathan I. Maletic

jmaletic@ksu.edu

10,000.17

1991999

Saleh M. Alnaeli

alnaelis@uwstout.edu

5,000.11

1333333

Bill Bultman

Bill.bultman@uwc.edu

120,000.00

 
	

Account Number : 1333333

Name           : Bill Bultman

Email          : Bill.bultman@uwc.edu

Balance        : 120,000.00

-------------------------------------

Account Number : 1201077

Name           : Jonathan I. Maletic

Email          : jmaletic@ksu.edu

Balance        : 10,000.17

-------------------------------------

Account Number : 1991999

Name           : Saleh M. Alnaeli

Email          : alnaelis@uwstout.edu

Balance        : 5,000.11

-------------------------------------

 

    Hint: Use multiple (4) arrays to hold the record fields and sort them based on the account balance array.
    Please take a look at the example posted on Piazza and Canvas (students' information example.)

*/