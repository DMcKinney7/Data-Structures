#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
using namespace std;
void createFile(string filePath,int SIZE);
void printLetters(const vector <char> &letters, int SIZE);
void sortLetters(vector <char> &letters);

int main()
{
    vector <char> letters;
    ifstream inFile;
    int SIZE = 30000;
    string filePath = "data/letters.txt";
    char UserSelection;

    inFile.open("letters.txt"); 
    do{        
        cout << "1: Create File" << endl;
        cout << "2: Print Letters" << endl;
        cout << "3. Sort Letters" << endl;
        cout << "E. Exit" << endl;
        cout << "Please Enter Your Selection" << endl;

        cin >> UserSelection;

        switch(UserSelection) {

            case '1': createFile(filePath,SIZE); break;
            case '2': printLetters(letters, SIZE); break;
            case '3': sortLetters(letters); break;
            case 'E' || 'e':break;
            default: cout << "Unknown Selection!" << endl; break;
        }
    } while(UserSelection != 'E' && UserSelection != 'e');
    inFile.close();
    return 0;
} 

void sortLetters(vector <char> &letters)
{
    for (int i = 0; i < letters.size(); ++i)
    {
        for (int j = i+1; j < letters.size(); ++j)
        {
            if (letters[i] > letters[j])
                swap(letters[i], letters[j]);
        }
    }
}

void printLetters(const vector <char> &letters, int SIZE)
{
    for (char letter : letters)
        cout << letter << " ";
    cout << endl;
}

void createFile(string filePath, int SIZE)
{
    int seed = time(nullptr); // get current time as seed
    ofstream outFile;
    outFile.open("data/letters.txt");
    srand(seed); // seed the random number generator
    for (int i = 0; i < SIZE; ++i)
        outFile << (char)('A' +(rand() % 24));  // generate random letter from A to X            
    outFile.close();
    cout << "File created." << endl;
    
}

/*
Scope
Write a C++ program that randomly generates 30000 characters (English Letters from A to X, all Uppercase) and then does the following:

    finds how many times the letter ‘O‘ was generated after the letter ‘M’ (How many times the letter 'M’ was followed by ‘O’)?
    print the letters sorted in increasing (non-decreasing) order.
*/