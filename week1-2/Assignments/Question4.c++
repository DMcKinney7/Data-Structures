#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

int main()
{
    int seed = time(nullptr); // get current time as seed
    srand(seed); // seed the random number generator
    for (int i = 0; i < 30000; ++i)
        (char)('A' +(rand() % 24)); 
        
        
        return 0;
    
} 

/*
Scope
Write a C++ program that randomly generates 30000 characters (English Letters from A to X, all Uppercase) and then does the following:

    finds how many times the letter ‘O‘ was generated after the letter ‘M’ (How many times the letter 'M’ was followed by ‘O’)?
    print the letters sorted in increasing (non-decreasing) order.
*/