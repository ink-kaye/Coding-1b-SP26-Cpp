// Keira Vilaysing Coding 1 Spring 2026
// Variables and Logic

// compile with the developer command prompt
// 'cl /EHsc main.cpp' is what you type to compile
// 'main' or 'main.exe' to run program

#include <iostream>
using namespace std;

int main () {
    cout << "Let's learn about variables and logic!\n"; 
    
    // declaring and defining variables
    int playerAge = -1;
    string playerName = "Darth Vader";
    float happinessPercentage = 0.61f; 
    bool keepPlaying = true;

    // just like a branch in unreal engine
    // if (the test is true) run this code
    if(playerAge == -1) {
        cout << "How old are you?\n";
        cin >> playerAge;

        if(playerAge <=12) {
            cout << "You're the youngest person ever! I'm sorry, this game is for grownups!\n";
            return 0; // quit game early
        }
        else {
            cout << "Wow, " << playerAge << " years, that is a long time\n";
        }
    } // end of if(playerAge)

    if(playerName == "Darth Vader") {
        cout << "is your name " << playerName << "?\n";
        string input;
        cin >> input; 

        // the OR operator '||' means that if any test evaluates to true, the if statment is true
        if(input == "yes" || input == "Yes" || input == "YES" || input == "yeah") {
            cout << "Well, that's convient!\n";
        }
        else {
            cout << "What is your name\n";
            cin >> playerName;
        }

        cout << "Hello " <<playerName << ".\n";

    } // end of if(playerName)

    // the AND operater '&&' requires that all tests are true

    bool debug = false; // turn this on to debug the program
    if(playerAge == 19 && playerName == "Keira") {
        debug = true;
        cout << "Helloo Creator. Debug mode is ON.\n";

    } // end of if(age && name)

    if(debug) {
        cout << "\n\tDEBUG MODE\n\n";
        cout << "playerAge = " << playerAge << ".\n";
        cout << "playerName = " << playerName << ".\n";
        cout << "happinessPercentage = " << happinessPercentage << ".\n";
        cout << "keep Playing = " << keepPlaying << ".\n";
    }

    

    return 0;
} // end of main ()