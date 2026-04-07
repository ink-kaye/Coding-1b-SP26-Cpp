// Keira Vilaysing Coding 1 SPring 2026
// Arrays, For loops, enums, and switch statements

#include <iostream>
#include <string>
#include <cstdlib> // for rand () and srand()
#include <ctime> // for time

using namespace std;

int main() {
    srand(time(0));
    cout << "Let's make some arrays\n";

    // arrays cannot change their size
    // arrays dont know where teh "last index" is
    // arrays are a list of similar variable type
    // arrays are ordered

    int scores[5];  // this is creating an integer array witih a size of 5

    scores[0] = 4545;
    scores[1] = 13;
    scores[2] = 9001;
    scores[3] = 2456;
    scores[4] = -4; 
    // scores[5] = 99999; //can't go past the size of the array.

    cout << "The first score is " << scores[0] << ".\n";

    cout << "Here are all of the scores:\n";

    int index = 0;
    while(index < 5) {
        cout << scores[index] << "\n";
        index++; 
    } 
    
    cout << "Using a for loop:\n";
    // for loop has the 'iterator' built in. 
    // for(setup; test; action)
    for(int i = 0; i < 5; i++) {
        cout << scores[i] << "\n";
    }

    // String array for names
    string names[10];
    string input;
    index = 0; // reset index so that we can use it again
    // we want the user to add names to the array
    while(index < 10 ) {
        cout << "Type name, or 'done':",
        cin >> input;

        // until they type done
        if(input == "done") { 
            cout << "\nDone adding names.\n";
            break;  // stop looping
        }

        // add the name to the array
        // then add 1 to the index wiht the increment operator
        names[index++] = input;

    } 
    // or until the list is full
    // show the list of names
    for(int i = 0; i < 10; i++) {
        if(names[i] == ""){
            continue;   //Start the loop over early. 
        }

        cout << names[i] << "\n";
        
    }

    // create a new string array
    string newNames[] = {"Mario", "Luigi", "Peach", 
                        "Captain Toad", "Bowser", "Rosalina", 
                        "Yoshi", "Bowser Jr.", 
                        };
        
        cout << "Here are the new names:\n";
        for(int i = 0; i < 8; i++) {
            cout << i + 1 << ". " << newNames[i] << "\n";
        }

    // pick a random name from out newNames array  
    int randIndex = rand() % 8; //slow way of learning  
    string  character = newNames[rand() % 8];
    
    cout << character << ", Let's talk about them.\n";
    
    // an enumerator is a custom variable tupe
    // with only the values that we specify
    // they correspond to numbers, starting with 0 by default. 
    enum favor {LOVE, LIKE, DISLIKE, LOATHE}; 
    enum difficulty {EASY, NORMAL, HARD, IMPOSSIBLE}; // examples
    enum shirtSize {EXTRA_SMALL, SMALL, MEDIUM, LARGE, EXTRA_LARGE}; // example

    switch(rand() % 4) { 
        case LOVE: 
            cout << "I love " << character << ".\n"; 
            break;
        case LIKE:
            cout << "I like " << character << ".\n"; 
            break;
        case DISLIKE:
            cout << "I dislike " << character << ".\n";
            break; 
        case LOATHE: 
            cout << "I loathe " << character << ".\n"; 
            break; 
    }

    return 0;
}