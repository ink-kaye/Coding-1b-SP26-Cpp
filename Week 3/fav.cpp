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
            favGames.push_back(input);

            cout << "Here are your games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            } // end of add
        }
        // edit (change one of the names)
        else if(input == "edit") {
            // show list, use iter to point to one to change it.
            // build iter
            vector<string>:: iterator iter;

            cout << "Here are your favs:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }
            // Make iter point at the first element in the vector
            iter = favGames.begin();

            cout << "The iter is pointing at " << *iter << ".\n";
            cout << "What game would you like to select?\n";
            getline(cin, input);

            // use find algorithm
            iter = find(favGames.begin(), favGames.end(), input);
            
            if(iter != favGames.end()) {
                cout << "We found " << *iter << ".\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);

                if(input == "yes"){
                    cout << "What would you like to change this too?\n";
                    getline(cin, input);

                    *iter = input; //changing fav
                }
                cout << "Here are your updated games!\n";
                for(int i = 0; i < favGames.size(); i++) {
                    cout << "\t" << favGames[i] << "\n";
                }
            }
            else{
                cout << "We couldn't find that name.\n";
            }
        }
        // remove (removes name from list)
        else if(input == "remove") {
            cout << "Here are your games!\n";
            for(int i = 0; i < favGames.size(); i++) {
              cout << "\t" << favGames[i] << "\n";
            }
            
            cout << "What game would you like to remove from the list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've found that name. Removing now.\n";
                favGames.erase(iter);   // remove the element the iter is pointing at.
            }
            cout << "Here are your games!\n";
            for(int i = 0; i < favGames.size(); i++) {
              cout << "\t" << favGames[i] << "\n";
            }
        }   //end remove
        // show (show the list, sorted)
        else if(input == "show") {
            sort(favGames.begin(), favGames.end());

            cout << "Here are your games!\n";
            for(int i = 0; i < favGames.size(); i++) {
              cout << "\t" << favGames[i] << "\n";
            }
        }
        // quit (quit)
        else if (input == "quit") {
            cout << "Thanks for playing!\n";
            break;
        } // end of quit
        else {
            cout << "I didn't recognize that command.\n";
        }    
    } while(true);  // end of while loop

    return 0;

}