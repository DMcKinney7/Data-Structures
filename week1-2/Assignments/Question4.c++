#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
void createFile(string filePath,int listSize);
void printLetters(char* letters, int listSize);
void sortLetters(char* letters, int listSize);
int countMO(const vector<char>& letters);

int main()
{
    vector <char> letters;
    int listSize = 30000;
    string filePath = "data/letters.txt";
    char UserSelection;

    do{        
        cout << "1: Create File" << endl;
        cout << "2: Print Letters" << endl;
        cout << "3. Sort Letters" << endl;
        cout << "4. Count 'O's after 'M's" << endl;
        cout << "E. Exit" << endl;
        cout << "Please Enter Your Selection" << endl;

        cin >> UserSelection;

        switch(UserSelection) {

            case '1':
                createFile(filePath, listSize);
                break;
            case '2': {
                // Load letters from file before printing
                letters.clear();
                ifstream inFile(filePath);
                char ch;
                while (inFile.get(ch)) {
                    letters.push_back(ch);
                }
                inFile.close();
                if (!letters.empty())
                    printLetters(letters.data(), letters.size());
                else
                    cout << "No letters loaded. Please create the file first." << endl;
                break;
            }
            case '3': {
                // Load letters from file before sorting
                letters.clear(); // Clear previous letters
                ifstream inFile(filePath); // Open the file
                char ch; // Variable to hold each character
                while (inFile.get(ch)) { // Read characters one by one
                    letters.push_back(ch); // push_back is to add elements to vector
                }
                inFile.close();
                if (!letters.empty()) {
                    sortLetters(letters.data(), letters.size());
                    cout << "Letters sorted." << endl;
                } else {
                    cout << "No letters loaded. Please create the file first." << endl;
                }
                break;
            }
            case '4': {
                // Load letters from file before counting
                letters.clear();
                ifstream inFile(filePath);
                char ch;
                while (inFile.get(ch)) {
                    letters.push_back(ch);
                }
                inFile.close();
                if (!letters.empty()) {
                    int count = countMO(letters);
                    cout << "Number of times 'M' is followed by 'O': " << count << endl;
                } 
                else {
                    cout << "No letters loaded. Please create the file first." << endl;
                }
                break;
            }
            case 'E':
            case 'e':
                break;
            default:
                cout << "Unknown Selection!" << endl;
                break;
        }
    } while(UserSelection != 'E' && UserSelection != 'e');
    return 0;
} 

int countMO(const vector<char>& letters) {
    int count = 0;
    for (size_t i = 0; i < letters.size() - 1; i++) {
        if (letters[i] == 'M' && letters[i + 1] == 'O') {
            count++;
        }
    }
    return count;
}

void sortLetters(char* letters, int listSize)
{
    // Sort the letters in-place
    sort(letters, letters + listSize);

    cout << "Sorted letters:" << endl;
    for (int i = 0; i < listSize; ++i) {
        cout << letters[i];
    }
    cout << endl;
}

void printLetters(char* letters, int listSize)
{
    for (int i = 0; i < listSize; ++i)
        cout << letters[i] << " ";
    cout << endl;
}

void createFile(string filePath, int listSize)
{
    int seed = time(nullptr); // get current time as seed
    ofstream outFile;
    outFile.open("data/letters.txt");
    srand(seed); // seed the random number generator
    for (int i = 0; i < listSize; ++i)
        outFile << (char)('A' +(rand() % 24));  // generate random letter from A to X            
    outFile.close();
    cout << "File created." << endl;
    
}