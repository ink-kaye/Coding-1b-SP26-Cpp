// Keira Vilaysing Coding 1 Spring 2026
// Making some critters I guess. 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>    // for random numbers
#include <cstdlib>  // random numbers
#include <algorithm> // for random shuffle

using namespace std;

vector<string> elemTypes = {"Fire", "Water", "Grass"};
vector<string> names;

class baseElemental {
public:     
// private:
    // base stats for the creatures. 
    string name;
    int health;
    int damage;
    int hunger;
    int startingHealth = 0;
    string element; 

public:
    // constructor

    baseElemental(string givenName, int givenHealth, int givenHunger, int givenDamage, string givenElement = "Random") {
        name = givenName;
        health = givenHealth;
        hunger = givenHunger;
        damage = givenDamage;
        if(givenElement == "Random") element = elemTypes[rand()% elemTypes.size()];

        cout << "A " << element << " elemental has been formed!\n";
    }

    // damage multipliers
    void attack(baseElemental& opponent) {
        if(element == "Water" && opponent.element == "Fire") {
            // do double damage
            opponent.health -= damage * 2;
        }
        else if(element == "Fire" && opponent.element == "Grass") {
            opponent.health -= damage * 2;
        }
        else if(element == "Water" && opponent.element == "Grass") {
            opponent.health -= damage * 0.5f;
        }
        else {
            opponent.health -= damage;
        }
    }

    void status() {
        cout << "My health is " << health << ".\n";
        cout << "I do " << damage << " base damage\n";
        cout << "My hunger is " << hunger << ".\n";
        cout << "I am ";

        if(hunger < 5) cout << "Satisfied";
        else if(hunger < 10) cout << "getting hungry...";
        else if(hunger < 15) cout << "not battling or training!";
        else cout << "HANGRY!>:(";

        cout << ".\n";     // end the sentence

    }

    //getters
    string getName() {
        return name;
    }

    int getHealth() {
        return health;
    }

    int getHunger() {
        return hunger;
    }
    int getDamage() {
        return damage;
    }

    // setter 
    void setName(string givenName) {
        if(givenName.size() <= 10) {
           name = givenName;
        }
        else {
            cout << "error: " << givenName << "is too long.\n";
        }
    }

    void setHealth(int givenHealth) {
        // clamp charge to between 0 - 100
        if(givenHealth < 5) health = 0; // floor is 0
        else if(givenHealth > 100) health = 100;    // ceiling is 100
        else health = givenHealth;
    }

    void setHunger(int givenHunger) {
        if(givenHunger > 20) hunger = 20; // clamp max to ceiling 20
        hunger = givenHunger;
    }
    
    void setDamage(int givenDamage) {
        if(givenDamage < 2) damage = 0; // floor is 0
        else if(givenDamage > 50) damage = 50; // ceiling 50
        else damage = givenDamage; 
    }


};

void read(vector<string>& vec, string path = "names.txt") {
    string line;
    ifstream readFile(path);
    if(readFile.is_open()) {
        while(getline(readFile, line)) {
            vec.push_back(line); 
        }
    }
    else {
        cout << "Couldn't open that file.\n";
    }

    // after we're done with the file, close it
    readFile.close();

}

int main() {
    string input;
    srand(time(0));     // seed the random number generator

    cout << "What is your name?\n"; // ask player their name
    getline(cin, input);

    // create new elemental 
    cout << "An elemental friend is forming...\n";
    //name creature
    baseElemental nereid("Nereid", 20, 2, 4);
    cout << "What would you like to name your Elemental?\n";
    cout << "The name must be less than 10 letters.\n";

    cout << "Here's some examples: \n";
    read(names);
    for(int i = 0; i < names.size(); i++) {
        cout << "\t" << names[i] << "\n";
    }

    getline(cin, input);
    nereid.setName(input);
    
    cout << "You named you're elemental " << nereid.getName() << endl; 
    

    do {
        cout << "What would you like to do next?\n";
        cout << "You can 'train', 'feed', 'listen', or 'battle'!!\n";
        getline(cin, input);

        // train creature
        if(input == "train") {
            cout << nereid.getName() << " is getting stronger!\n";
            // add to health
            nereid.setHealth(nereid.getHealth() + 1);
            // add to damage
            nereid.setDamage(nereid.getDamage() + 1);
            // subtract from hunger
            nereid.setHunger(nereid.getHunger() + 1);

        }
        //feed elemental
        else if(input == "feed") {
            cout << "You're feeding your elemental!\n";
            // affect the hunger, it goes down
            nereid.setHunger(nereid.getHunger() - 1);
        }
        //display stats (health, hunger, damage)
        else if(input == "listen") {
            // not sure how to do this, is it just status from the WK5 file?
            nereid.status();
        }
        else if(input == "battle") {
            // another loop
            while(true) {
                
            }
            // create a boss elemental
            // battle others
                // attack
                // heal
                // run away
        }
        else {
            cout << "Your Elemental doesn't understand.\n";
        }

    } while(true);

    return 0;
}