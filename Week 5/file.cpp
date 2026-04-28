// Keira Vilaysing Coding 1 Spring 2026
// Classes

//self documenting code means the code can only do one thing, or be used one way



#include <iostream>
#include <string>
using namespace std;

// classes are custom variable types
// variables
//functions

// constructors
// getters and setters (privacy)

class robot {
private:
    // data members
    string name;
    int charge;
    int boredom;

public: 
    // constructor sets up the class with input variables
    // doesnt have a return type, must be named the same as class
    robot(string givenName, int givenCharge, int givenBoredom) {
        name = givenName;
        charge = givenCharge;
        boredom = givenBoredom;
        status();
    }

    // default constructor
    robot() {
        name = "Rob";
        charge = 10; 
        boredom = 10;
        status();
    }

    void status() {
        cout << "Hello, my name is " << name;
        cout << " and my charge is " << charge << ".\n";
        cout << "I am ";

        if(boredom < 5) cout << "happy";
        else if(boredom < 10) cout << "bored";
        else if(boredom < 15) cout << "getting angry...";
        else cout << "ENRAGED >:(";

        cout << ".\n";     // end the sentence

    }

    //getters
    string getName() {
        return name;
    }

    int getCharge() {
        return charge;
    }

    int getBoredom() {
        return boredom;
    }

    // setters
    void setName(string givenName) {
        if(givenName.size() <= 5) {
           name = givenName;
        }
        else {
            cout << "error: " << givenName << "is too long.\n";
        }
    }

    void setCharge(int givenCharge) {
        // clamp charge to between 0 - 100
        if(givenCharge < 5) charge = 0; // floor is 0
        else if(givenCharge > 100) charge = 100;    // ceiling is 100
        else charge = givenCharge;
    }

    void setBoredom(int givenBoredom) {
        if(givenBoredom > 20) boredom = 20; // clamp max to ceiling 20
        boredom = givenBoredom;
    }

    // does get and set at the same time. 
    void changeChargeBy(int amount = 1) {
        setCharge(charge += amount);
    }

}; // end if robot class

int main() {
    cout << "Classes!\n";

    //creat our first instance of a robot. 
    robot artoo("R2-D2", 45, 3);
    //  artoo.name = "R2-D2";   // dot syntax goes from large to small
    //  artoo.charge = 45;    
    //  artoo.boredom = 3; 
    cout << "Artoo has " << artoo.getName().size() << " letters in their name.\n";

    robot threepio;
    threepio.setName("C-3P0");      // using the setter
    threepio.setCharge(2);
    threepio.setBoredom(12);
    
    artoo.status();
    threepio.status();

    cout << "Threepio has low batterty, lets have artoo charge him up!\n";

    while(threepio.getCharge() < 15) {
        if(artoo.getCharge() > 0) {
            artoo.setCharge(artoo.getCharge() - 1);     // subtract 1 from artoo
            threepio.setCharge(threepio.getCharge() + 1); 
        }
        else {
            cout << "Artoo is out of energy!\n";
            break;
        }
    }

    return 0;
}