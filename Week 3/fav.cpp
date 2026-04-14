// Keira Vilaying Coding 1 Spring 2026
// fav games assignment

#include <iostream>
#include <string>       // for getline(), only gets strings
#include <vector>       // for vectors and iterators
#include <algorithm>    //for find(), sort(), random_shuffle()

using namespace std;

int main() {
    // start:
    cout << "Hello! This is the 'Favorite Games' Game (great name, I know).\n";
    // make a global vector of fav Games
    vector<string> favGames = {"Breath of the Wild", "Minecraft", "Animal Crossing"};

    // make string input
    string input;

    // Make do-while loop of what to do   
    do {  
        // Ask player what to do, get input for 
           // add, edit, remove, show, and quit
        cout << "What would you like to do?\n";
        cout << "You can type 'show', 'add', 'edit', 'remove', and 'quit'.\n";

        getline(cin, input); // Get input from player
        //start if lines
        // add (add name)
        if(input == "add") {
            // cout what name to add?
            cout << "What game would you like to add?\n";
            // get line from player
            getline(cin, input);
            // pushback (input)

        }
        // edit (change one of the names)
            // show list, use iter to point to one to change it.
        // remove (removes name from list)
        // show (show the list, sorted)
        // quit (quit)





    } while(true);  // end of while loop

}