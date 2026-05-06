// Keira Vilaysing Coding 1 Spring 2026
// Inheritence, Vectors of classes, and slime battling

#include <iostream>
#include <string>
#include <vector>
#include <ctime>    // for random numbers
#include <cstdlib>  // random numbers
#include <algorithm> // for random shuffle

using namespace std;

// this is a global vector, visible in all functions. 
vector<string> names = {"Alfred", "Barbara", "Quentin", "Sandra", "Glenn", "Betty"};

class baseSlime {
public:     
    string name;
    int health;
    int damage;

    int startingHealth = 0;

    // default constructor
    baseSlime() {
        cout << "a new slime has been formed.\n";
        name = names[rand() % names.size()] + " Slime";
        health = rand() % 4 + 4;
        startingHealth = health;    // save this for eventual boss. 
        damage = rand() % 3 + 3; 
    }

    void hello() {
        cout << "I'm " << name << ", with " << health << " health ";
        cout << "and " << damage << " damage.\n";
    }

    // attack another slime
    // return true if  opponent health <= 0
    bool attack(baseSlime& opponent) {
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0)    return true;
        else                        return false;
    }

};

class bossSlime : public baseSlime {
public: 
    int damageMultiplier = 3;

    // contructor for boss
    bossSlime() { 
        // should inherit health
        // should inherit the cout statement
        name = "boss";
        damage = damage * damageMultiplier;
    }

    // very straightforward to 'override' a function in the parent class.
    bool attack(baseSlime& opponent) {
        cout << "This is a boss attack!\n";
        opponent.health -= damage;
        cout << name << " has done " << damage << " damage to ";
        cout << opponent.name << "!\n";

        if(opponent.health <= 0)    return true;
        else                        return false;
    }

    void taunt() {
        cout << "I will crush your bones with my slime!\n";
    }
};

class splitSlime : public baseSlime {
    // build constructor to use half-starting health if the original slime
    // on death, add myself to a vector of dead slimes
        // that can be regenrated into a boss slime. 
};

int main () {
    srand(time(0));     // seed the random number generator
    cout << "SLIME BATTLES!\n";

    //create slime
    baseSlime gerald;
    gerald.name = "Gerald";
    gerald.hello();

    bossSlime destroyer;
    destroyer.name = "Destroyer";
    destroyer.hello();
    destroyer.taunt();

    cout << "Gerald is feeling cheeky...\n";
    gerald.attack(destroyer);

    cout << "Destroyer is enraged!\n";
    if(destroyer.attack(gerald)) {
        cout << "Gerald is no more. DEAD.\n";
    }

    // create a vector of slimes
    // then pick two to fight 
    //global variables

    // create a new vector of slimes with a size of 6
    vector<baseSlime> sludge(6);    

    if(rand() % 4 == 0) {
        bossSlime superSlime;
        sludge.push_back(superSlime);
    }

    cout << "Here's our sludge of Slimes:\n\n";
    for(auto& slime : sludge) {
        cout << slime.name << "\n";
    }

    random_shuffle(sludge.begin(), sludge.end());

    auto& a = sludge[0];    // a is equal to the first slime
    auto& b = sludge[1];    // b is equal to the second slime

    cout << a.name << " is fighting " << b.name << "!!!\n";

    while(a.health > 0 && b.health > 0) {
        if(a.attack(b)) {
            cout << b.name << " has been defeated by "; 
            cout << a.name << ".\n";
        }
        else {
            if(b.attack(a)) {
                cout << a.name << " has been defeated by "; 
                cout << b.name << ".\n";
            }
        }
    }

    return 0;
}