// Keira Vilaysing Coding 1 Spring 2026
// Making some critters I guess.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>     // for random numbers
#include <cstdlib>   // random numbers
#include <algorithm> // for random shuffle

using namespace std;

vector<string> elemTypes = {"Fire", "Water", "Grass"};
vector<string> names;

class baseElemental
{
private:
    //  base stats for the creatures.
    string name;
    int health;
    int hunger;
    int startingHealth = 0;
    string element;

public:
    int damage;
    // constructor
    baseElemental(string givenName, int givenHealth, int givenHunger, int givenDamage, string givenElement = "Random")
    {
        name = givenName;
        health = givenHealth;
        hunger = givenHunger;
        damage = givenDamage;
        if (givenElement == "Random")
            element = elemTypes[rand() % elemTypes.size()];

        cout << "A " << element << " elemental has been formed!\n";
    }

    // damage multipliers
    void attack(baseElemental &opponent)
    {
        cout << name << " does "  << element << " damage!\n";
        cout << "Receiver is " << opponent.name << " : " << opponent.element << " damage!\n";
        cout << name << " does " << damage << " base damage.\n";
        cout << opponent.name << " has " << opponent.health << " health\n";

        if (element == "Water" && opponent.element == "Fire")
        {
            // do double damage
            opponent.health -= damage * 2;
        }
        else if (element == "Fire" && opponent.element == "Grass")
        {
            opponent.health -= damage * 2;
        }
        else if (element == "Grass" && opponent.element == "Water")
        {
            opponent.health -= damage * 2;
        }
        else if (element == "Water" && opponent.element == "Grass")
        {
            opponent.health -= damage * 0.5;
        }
        else if (element == "Fire" && opponent.element == "Water")
        {
            opponent.health -= damage * 0.5;
        }
        else if (element == "Grass" && opponent.element == "Fire")
        {
            opponent.health -= damage * 0.5;
        }
        else
        {

            opponent.health -= damage;
        }
    }

    void status()
    {
        cout << "My health is " << health << ".\n";
        cout << "I do " << damage << " base damage\n";
        cout << "My hunger is " << hunger << ".\n";
        cout << "I am ";

        if (hunger < 5)
            cout << "Satisfied";
        else if (hunger < 10)
            cout << "getting hungry...";
        else if (hunger < 15)
            cout << "not battling or training!";
        else
            cout << "HANGRY!>:(";

        cout << ".\n"; // end the sentence
    }

    // getters
    string getName()
    {
        return name;
    }

    int getHealth()
    {
        return health;
    }

    int getHunger() 
    {
        return hunger;
    }
    int getDamage()
    {
        return damage;
    }

    // setter
    void setName(string givenName)
    {
        if (givenName.size() <= 10)
        {
            name = givenName;
        }
        else
        {
            cout << "error: " << givenName << "is too long.\n";
        }
    }

    void setHealth(int givenHealth)
    {
        // clamp charge to between 0 - 100
        if (givenHealth < 0)
            health = 0; // floor is 0
        else if (givenHealth > 100)
            health = 100; // ceiling is 100
        else
            health = givenHealth;
    }

    void setHunger(int givenHunger)
    {
        if (givenHunger > 20)
            hunger = 20; // clamp max to ceiling 20
        hunger = givenHunger;
    }

    void setDamage(int givenDamage)
    {
        if (givenDamage < 2)
            damage = 0; // floor is 0
        else if (givenDamage > 50)
            damage = 50; // ceiling 50
        else
            damage = givenDamage;
    }
};

class bossElemental : public baseElemental {
public:
    int damageMultiplier = 2;

    // default
    bossElemental()
        : baseElemental("Overlord", 40, 2, 5) {
        damage *= damageMultiplier;
    }

    // custom
    bossElemental(string givenName, int givenHealth, int givenHunger, int givenDamage)
        : baseElemental(givenName, givenHealth, givenHunger, givenDamage) {
        damage *= damageMultiplier;
    }
};

vector<string> read(string path = "names.txt")
{
    string line;
    vector<string> vec;
    ifstream readFile(path);
    if (readFile.is_open())
    {
        while (getline(readFile, line))
        {
            vec.push_back(line);
        }
        readFile.close();
        return vec;
    }
    cout << "Couldn't open that file.\n";

    // after we're done with the file, close it
    readFile.close();
    return vec;
}

int main() {
    string input;
    srand(time(0)); // seed the random number generator

    cout << "What is your name?\n"; // ask player their name
    getline(cin, input);

    // create new elemental
    cout << "An elemental friend is forming...\n";
    // name creature
    baseElemental nereid("Nereid", 20, 2, 4);
    cout << "What would you like to name your Elemental?\n";
    cout << "The name must be less than 10 letters.\n";

    cout << "Here's some examples: \n";
    names = read();
    for (int i = 0; i < names.size(); i++) {
        cout << "\t" << names[i] << "\n";
    }

    getline(cin, input);
    nereid.setName(input);

    cout << "You named you're elemental " << nereid.getName() << endl;

    do {
        if (nereid.getHunger() > 5){
            cout << "FEED ME" << endl;
            cout <<"My hunger level is: " << nereid.getHunger();
            cout <<" I CANT FIGHT OR TRAIN IF MY HUNGER IS 10 OR MORE" << endl;
        }
        cout << "What would you like to do next?\n";
        cout << "You can 'train', 'feed', 'listen', or 'battle'!!\n";
        getline(cin, input);

        // train creature
        if (input == "train")  {
            if (nereid.getHunger() > 10){
                cout << "im too hungry to train" << endl;
                continue;
            }
            cout << nereid.getName() << " is getting stronger!\n";
            // add to health
            nereid.setHealth(nereid.getHealth() + 3);
            // add to damage
            nereid.setDamage(nereid.getDamage() + 1);
            // subtract from hunger
            nereid.setHunger(nereid.getHunger() + 1);
        }
        else if (nereid.getHunger() >= 10){
            cout << "IM too hungry to train" << endl;
        }
        // feed elemental
        else if (input == "feed")  {
            cout << "You're feeding your elemental!\n";
            // affect the hunger, it goes down
            nereid.setHunger(nereid.getHunger() - 1);
        }
        // display stats (health, hunger, damage)
        else if (input == "listen")  {
            // not sure how to do this, is it just status from the WK5 file?
            nereid.status();
        }
        else if (input == "battle") {
            if (nereid.getHunger() > 10){
                cout << "I'm too hungry to battle " << endl;
                continue;
            }

            // create boss elemental
            bossElemental overlord("Overlord", 40, 2, 5);
            cout << "This is a boss.\n";
            
            // another loop
            while (overlord.getHealth() > 0 && nereid.getHealth() > 0)   {
                // battle others
                cout << "You can choose to 'attack', 'heal', or 'run'.\n";

                getline(cin, input);
                if(input == "attack") {
                    nereid.attack(overlord); 
                    cout << "Overlord now has " << overlord.getHealth() << " health.\n";
                    overlord.attack(nereid);
                    cout << "Your elemental has " << nereid.getHealth() << " health left!\n";
                }
                else if(input == "heal") {
                    cout << "You're being healed.\n";
                    // heal
                    nereid.setHealth(nereid.getHealth() + 5);
                    cout << nereid.getName() << " has " << nereid.getHealth() << " health now.\n";
                }
                // heal
                else if(input == "run") {
                    cout << "You are running away!\n";
                    break;
                }
                else {
                    cout << "Sorry, your elemental didn't understand.\n";
                }
            
            }
        }
        else {
            cout << "Your Elemental doesn't understand.\n";
        }

    } while (true);

    return 0;
}