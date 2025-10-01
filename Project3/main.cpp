/*Part 1: Inheritance and Abstract Classes [10 Points]

    Design and Implement an abstract class called ‘Drone’ that has the following members:
        A public String variable ‘droneName’ (holds the drone name. The default name is “Unknown Drone”
        A private Boolean variable ‘licensed’ (true for licensed drone and false otherwise).
        A private Decimal variable ‘payload’ (holds the payload of the drone, but it is 1.5  by default.)
        Two getters for the members described in 2 and 3.
        An abstract method (pure virtual) ‘void printPayload()’. (overridable if needed by children's classes)
        The class has a construct that is used for initializing the class members.
    Show (design and implement) how derivate a sub-class ‘ScientificDrone’ from the class ‘Drone’ described in B with two decimal class members ‘sensorsWeight’ and ‘batteryWeight’. Then provide a concrete implementation for the method printPayload inherited from the superclass ‘Drone’ such that it calculates and outputs the actual payload of the drone, based on the values stored in the class members, sensorsWeight and batteryWeight.

Please ensure that you implement proper constructors as well (initialize the inherited members from the parent and the child members). */
#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Drone {
public:
    string droneName;
    Drone(string name = "Unknown Drone", bool licensed = false, double payload = 1.5)
        : droneName(name), licensed(licensed), payload(payload) {}

    bool isLicensed() const { return licensed; }
    double getPayload() const { return payload; }

    virtual void printPayload() const = 0; // Pure virtual

protected:
    bool licensed;
    double payload;
};

// Derived class
class ScientificDrone : public Drone {
public:
    double sensorsWeight;
    double batteryWeight;

    ScientificDrone(string name = "Unknown Drone", bool licensed = false, double payload = 1.5,
                    double sensorsWeight = 0.0, double batteryWeight = 0.0)
        : Drone(name, licensed, payload),
          sensorsWeight(sensorsWeight), batteryWeight(batteryWeight) {}

    void printPayload() const override {
        double actualPayload = payload + sensorsWeight + batteryWeight;
        cout << "Drone Name: " << droneName << endl;
        cout << "Licensed: " << (licensed ? "Yes" : "No") << endl;
        cout << "Actual Payload: " << actualPayload << " kg" << endl;
    }
};

// Example usage
int main() {
    ScientificDrone sd("SciDrone-1", true, 1.5, 0.7, 0.8);
    sd.printPayload();
    return 0;
}
