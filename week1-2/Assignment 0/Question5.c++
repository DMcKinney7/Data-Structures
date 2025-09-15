#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;

struct vehicle{
    string VIN;
    double Price;
};

bool comp(const vehicle &a, const vehicle &b) {
    return a.Price < b.Price;
}
int main(){
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