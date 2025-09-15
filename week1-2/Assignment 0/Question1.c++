#include <iostream>
using namespace std;

int main()
{
    double weight;
    char contPrompt ;
    
    do
    {
        cout << "Please Enter the Weight in pound: ";
        cin >> weight;
            if(weight >= 6 && weight <= 11.99){
                cout << "The Dosage is: 1.25 ML" << endl;
            }

            else if (weight >= 12 && weight <= 17.99){
                cout << "The Dosage is: 2.5 ML" << endl;
            }

            else if (weight >= 18 && weight <= 35.99){
                cout << "The Dosage is: 5 ML" << endl;
            }

            else if (weight >= 36){
                cout << "The Dosage is: 15 ML" << endl;
            }

            else {
                cout << "Invalid Entry!" << endl;
            }
        
        cout << "Another Case? [y/n] ";
        cin >> contPrompt;
    }while (contPrompt == 'y' || contPrompt == 'Y');
    
    cout << "Goodbye!" << endl;

}