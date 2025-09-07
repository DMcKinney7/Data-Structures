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
        cout << "How many " << pizza[pizzaChoice - 1].pizzaName << " pizzas would you like? ";
        cin >> pizzaQuantity;
        cout << """ << jokes[rand() % 5] << """ << endl;
        
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

/*
https://www.w3schools.com/cpp/cpp_enum.asp

Scope
Question 9: The Great Pizza Order Automation [15 points]

Assume that you are offered an internship position and your first job is to write a C++ program for a restaurant. The program is used for automating its pizza ordering process. So, your mission is to write a C++ program to help the staff process customer orders efficiently while keeping things light-hearted and fun. 
Requirements:

    Create a Menu:
        Use arrays to store a list of pizza types (e.g., Margherita, Pepperoni, Veggie Supreme, etc.) and their corresponding prices.
        Display the menu to the user in a stylish and humorous format.

    Take an Order:
        Prompt the user to enter the number corresponding to their pizza choice and the quantity.
        Add a random joke about pizza whenever they select an item (e.g., “Why did the pizza maker become a comedian? Because they know how to deliver!”).

    Calculate the Total:
        Use a loop to allow the user to order multiple items.
        Keep track of the total cost and display it at the end.

    Apply Discounts:
        If the total exceeds $50, apply a 10% discount and let the customer know with a celebratory message like, “You’re a pizza pro—discount unlocked!”

    Extra Credit (Optional):
        Use a function to display a summary of the order, including the total number of pizzas and their final cost after discounts.
        Add a surprise “Chef’s Special” item if the order total hits an odd number.

Sample Output:

Welcome to Pizza Palace!
Our Menu:
1. Margherita - $10
2. Pepperoni - $12
3. Veggie Supreme - $11
4. Meat Lover’s - $14
5. BBQ Chicken - $13

Enter the number of the pizza you’d like to order: 2
How many Pepperoni pizzas would you like? 3
"Pepperoni is the life of the pizza party!"

Would you like to order another pizza? (y/n): y

Enter the number of the pizza you’d like to order: 1
How many Margherita pizzas would you like? 2
"Margherita: Keeping it classic since forever!"

Would you like to order another pizza? (y/n): n

Your Order Summary:
3 x Pepperoni - $36
2 x Margherita - $20
Total: $56
Congratulations! You unlocked a 10% discount.
Final Total: $50.4
Thank you for visiting Pizza Palace! Have a crust-tastic day!

*/