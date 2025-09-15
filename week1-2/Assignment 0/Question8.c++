#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>


using namespace std;


void initialize(vector<int>& lotteryNumbers);
bool check(int tempLotto,const vector<int>& lotteryNumbers);
void generate(vector<int>& lotteryNumbers);
void printOut(const vector<int>& lotteryNumbers, int userLotto);
int input();



int main(){
    int seed = time(nullptr);
    srand(seed);
    vector<int> lotteryNumbers;
    int userLotto;

    initialize(lotteryNumbers);  

    generate(lotteryNumbers);

    userLotto = input();
    if(check(userLotto,lotteryNumbers)){
        cout << "You won!\n" << endl;
    } else {
        cout << "Sorry, you did not win.\n" << endl;
    }

    printOut(lotteryNumbers, userLotto);

}


void initialize(vector<int>& lotteryNumbers){
    for (int i = 0; i < 15; ++i){
        lotteryNumbers.push_back(0);
    }
}


bool check(int tempLotto,const vector<int>& lotteryNumbers){
    for (int i = 0; i < lotteryNumbers.size(); ++i){
        if (lotteryNumbers[i] == tempLotto){
            return true;
        }
    }
    return false;
}


void generate(vector<int>& lotteryNumbers){
    for (int i = 0; i < lotteryNumbers.size(); ++i){
        int tempLotto;
        do {
            tempLotto = rand() % 999 + 1;
        } while (check(tempLotto, lotteryNumbers));
        lotteryNumbers[i] = tempLotto;
    }       
}


void printOut(const vector<int>& lotteryNumbers, int userLotto){
    for (int i = 0; i < lotteryNumbers.size(); ++i){
        cout << lotteryNumbers[i] << endl;
    }
    cout << "Lottery number: " << userLotto << endl;
    cout << endl;
}


int input(){
    int userInput;
    cout << "Enter your lottery number(1 thru 999): ";
    cin >> userInput;
    
    return userInput;
}
