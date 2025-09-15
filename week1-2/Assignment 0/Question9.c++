#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

struct pizzaIndex{
        int pizzaNumber;
        string pizzaName;
        double pizzaPrice;
    };

struct orderItem {
    int pizzaIndex;
    int quantity;
};

void menu(vector<pizzaIndex>& pizza);
void initialize(vector<pizzaIndex>& pizza);

int main(){
    vector<pizzaIndex> pizza;
    initialize(pizza);
    menu(pizza);
    char userSelection;
    double discount = 0, subTotal = 0, finalTotal = 0;
    vector<orderItem> currentOrder;
    int seed = time(nullptr);
    srand(seed);
    vector<string> jokes = {
        "Why did the pizza maker become a comedian? Because they know how to deliver!",
        "What type of person doesn't like pizza? A weir-dough!",
        "Why did the hipster burn his mouth on the pizza? He ate it before it was cool.",
        "What's a pizza's favorite movie? Pie Hard.",
        "Why did the pizza go to the party alone? Because it was a little slice of life!"
    };

    do{
        int pizzaChoice, pizzaQuantity;
        cout << "\nEnter the number of the pizza you’de like to order: ";
        cin >> pizzaChoice;

        while(cin.fail() || pizzaChoice < 1 || pizzaChoice > pizza.size()){
            cout << "Invalid choice. Please enter a number from 1 to " << pizza.size() << ": ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> pizzaChoice;
        }

        cout << "How many " << pizza[pizzaChoice - 1].pizzaName << " pizzas would you like? ";
        cin >> pizzaQuantity;
        cout << jokes[rand() % 5] << endl;
        
        currentOrder.push_back({pizzaChoice, pizzaQuantity});

        cout << "\nWould you like to order another pizza? (y/n): ";
        cin >> userSelection;
    }while(userSelection == 'y' || userSelection == 'Y');
    
    cout << "\nYour Order Summary:\n";
    for(const auto& order : currentOrder){
        double itemTotal = pizza[order.pizzaIndex - 1].pizzaPrice * order.quantity;
        cout << order.quantity << " x " << pizza[order.pizzaIndex - 1].pizzaName << " - $" << itemTotal << endl;
        subTotal += itemTotal;
    }

    cout << "Total: $" << subTotal << endl;
    if(subTotal > 50){
        cout << "Congratulations! You unlocked a 10% discount." << endl;
        finalTotal = subTotal * 0.9;
        cout << "Final Total: $" << finalTotal << endl;
    }else{
        finalTotal = subTotal;
    }
    cout << "Thank you for visiting Pizza Palace! Have a crust-tastic day!" << endl;
    return 0;

}

void menu(vector<pizzaIndex>& pizza){
    cout << "Welcome to Pizza Palace!" << endl;
    cout << "Our Menu:" << endl;
    for(const auto& p : pizza){
        cout << p.pizzaNumber << ". " << p.pizzaName << " - $" << p.pizzaPrice << endl;
    }
    
}

void initialize(vector<pizzaIndex>& pizza){
    pizza.push_back({1, "Margherita", 10.0});
    pizza.push_back({2, "Pepperoni", 12.0});
    pizza.push_back({3, "Veggie Supreme", 11.0});
    pizza.push_back({4, "Hawaiian Pizza", 14.0});
    pizza.push_back({5, "BBQ Chicken", 13.0});
}
