#include <iostream>
#include <cmath>
#include <string>
//using std::cout;
using namespace std; //Similar in functionality but not recommended because it can lead to name conflicts.

int main() 
{
    int userEntry;
    cout << "Press 1 to print Hi!\n" << "Press 2 to print Bye!\n";
    cin >> userEntry;
switch (userEntry)
{
case 1:
    cout << "Hi!" << endl;
    break;

case 2:
    cout << "Bye!" << endl;

default:
    cout << "Invalid Entry!" << endl;
    break;
}
    // if-else statement review
    // if (userEntry == 1)
    // {
    //      cout << "Hi!" << endl;
    // }
    // else if (userEntry == 2)
    // {
    //      cout << "Bye!" << endl;
    // }
    // else
    // {
    //     cout << "Invalid Entry!" << endl;
    // }
    


    // string myAddress;
    // string dummyReader;
    // string fullName;
    // int myID;
    // cout << "Please enter your ID number, full name and address: \n";
    // cin >> myID; //cin stops reading input when it encounters a space. So if the address has spaces it will only read the first word.
    // cin.ignore(1000, '\n'); //this line is used to clear the input buffer before using getline. The 1000 is the maximum number of characters to ignore and '\n' is the delimiter.
    // //getline(cin, dummyReader); //this line is used to clear the input buffer before using getline.
    // getline(cin, fullName);
    // getline(cin, myAddress);
    // cout << "You Entered: " << myID << ", "<< fullName << ", " << myAddress << endl;
    

    /*string myAddress;
    cout << "Please enter your address: ";
    //cn >> myAddress; //this will only read the first word of the address.
    getline(cin, myAddress); //this will read the entire line including spaces until the user hits enter.
    cout << "You Entered:\t" << myAddress << endl;*/

    
    /*
    int userEntryInt;
    bool Yes;
    double dblValue;
    char charValue;
    string myFirstName;
    string myAddress;

    cout << "Please enter your ID Number, Balance, a char, address: ";//when doing the cin after this make sure to enter the values in the same order as requested.

    cin >> userEntryInt >> dblValue >> charValue>> myAddress; //cin stops reading input when it encounters a space. So if the address has spaces it will only read the first word.

    cout << "You Entered:\t" << userEntryInt << "\t" << dblValue << "\t" << charValue << "\t" << myAddress << endl;

    cout << "You entered: " << userEntryInt << endl; //endl is used to insert a new line and flush the output buffer.
    
    cout <<1<<"\t"<<"Hello, World!\n"<< pow(10,2) << endl;
    */
}
