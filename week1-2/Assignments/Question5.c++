#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

bool comp(int a, int b) {
    return a < b;
}
int main(){
    struct vehicle{
        string VIN;
        double Price;
    } ;
    int N;//number of vehicles
    cout << "Enter the number of vehicles: " << endl;
    cin >> N;
    
    vector<vehicle> vehicles(N);
    for (int i = 0; i < N; i++)
    {
        cout << "Enter VIN: " << endl;
        cin >> vehicles[i].VIN;
        cout << "Enter Price: " << endl;
        cin >> vehicles[i].Price;
    }


    sort(vehicles.begin(), vehicles.end(), comp);
    cout << "Vehicles Information (Sorted):" << endl;
    for (const vehicle &v : vehicles)
    {
        cout << "VIN: " << v.VIN << ", Price: " << fixed << setprecision(2) << v.Price << endl;
    }
}


/*  
Scope
Question 4:

Write a C++ program that reads N vehicles information ( VIN number, and Price), and then prints them sorted based on their price in increasing order such that the cheapest vehicle information is printed first and the most expensive one is printed last.

The vehicle information is entered as a set of two fields (pieces of information) as shown below:

Vehicle VIN (string)

Vehicle Price (double)

The program is expected to read the number of the records (N) from the user and then the vehicles' information and then prints the vehicles sorted in increasing order based on the price.

Example:

 
Input 	Output

XYZ1234UHN9869

45000.75

TYU2349864H9812

10000.50

VTL92836964H234

250000.00
	

VIN: TYU2349864H9812

Price: 10000.50

VIN: VTL92836964H234

Price: 250000.00

VIN: XYZ1234UHN9869

Price: 45000.75
*/