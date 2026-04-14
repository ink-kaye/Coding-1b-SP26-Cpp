// Keira Vilaying Coding 1 Spring 2026
// Vectors, Interators and Algorithms

// for windows, it's "cl /EHsc vec.cpp && vec"
// this is to compile and run in one line. 

#include <iostream>
#include <string>       // for getline(), only gets strings
#include <vector>       // for vectors and iterators
#include <algorithm>    //for find(), sort(), random_shuffle()

using namespace std;

int main() {
    cout << "Let's learn vectors!\n";

    // Make a globalish vector of favs, so that 
        // we are able to see out changes through the loops
    // talk about the 'auto' variable type
    // talk about removing with .erase()
    // sorting with sort()
    // then start homework

    // this vector exists outside of the do-while loop
    // so it won't be destoryed every loop. 
    vector<string> favGames = {"Genshin Impact", "Honkai Star Rail", "Animal Crossing"};

    string input;
    // int numberInput = stoi(input);
    

    do {
        cout << "What would you like to do?\n";
        cout << "You can type 'quit', 'push', 'find', 'remove'.\n";

        getline(cin, input);    //Get input from player

        if(input == "push") {
            cout << "\nLet's make our first vector of strings.\n";

            vector<string> names;

            // add some names with names.push_back()
            names.push_back("Finn");
            names.push_back("Lady Rainicorn");
            names.push_back("Jake");
            names.push_back("the Lich");
            names.push_back("Lemongrab");

            cout << "Here are your names.\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }

            cout << "There are " << names.size() << " names.\n\n";

            cout << *(names.end() - 1) << " is sour. Let's get rid of them.\n";

            names.pop_back();   // Removes the last element from the vector. 

            cout << "Here are your names.\n";
            for(int i = 0; i < names.size(); i++) {
                cout << "\t" << names[i] << "\n";
            }


        } // end of 'push'
        else if(input == "find") {
            cout << "Let's try to use the find algorithm.\n";

            // using a collection initiallizer  to add favs at creation of vector
            vector<string> favs = {"Pursuit of Jade", "Ponyo", "Howl's Moving Castle"};

            // building an iterator. it points to a 'spot' in  a vector.
            vector<string>:: iterator iter;

            cout << "Here are your favs!\n";
            for(int i = 0; i < favs.size(); i++) {
                cout << "    " << favs[i] << "\n";
            }

            // make iter point at the first element in the vector
            iter = favs.begin();

            // The asterick is a "dereference operator"... so that we can get
                // the value that the iter is pointing at.
            cout << "iter is pointing at " << *iter << ".\n";

            iter += 1; 

            cout << "Now iter is pointing at " << *iter << ".\n";

            cout << "What name would you llike to select?\n";
            getline(cin, input);

            // use the find algorithm
            iter = find(favs.begin(), favs.end(), input);

            if(iter != favs.end()) {
                cout << "We've found " << *iter << ".\n";
                cout << "Would you like to change this fav?\n";
                getline(cin, input);
                
                if(input == "yes") {
                    cout << "What would youl like to change this fav to?\n";
                    getline(cin, input);

                    *iter = input; // changing  the fav. 
                }
                 cout << "Here are your updated favs!\n";
                 for(int i = 0; i < favs.size(); i++) {
                cout << "    " << favs[i] << "\n";
                } 
            }
            else{
                cout << "We couldn't find that name.\n";
            }


        }
        else if(input == "quit") {
            cout << "Thanks for playing\n";
            break;
        }
        else if(input == "remove") {
            // sort the favgames vector alphabetically
            sort(favGames.begin(), favGames.end());

            cout << "Here are your favorite Games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }

            cout << "What game would you like to remove from the list?\n";
            getline(cin, input);

            auto iter = find(favGames.begin(), favGames.end(), input);

            if(iter != favGames.end()) {
                cout << "We've fount that name. Removing now.\n";
                favGames.erase(iter);   // remove the element the iter is pointing at.
            }
             cout << "Here are your favorite Games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << favGames[i] << endl;
            }
        }   //end of remove
        else {
            cout << "I didn't recognize that command.\n";
        }
    } while(true);

    // create a new vector of strings

    return 0;
}