// Keira Vilaysing Coding 1 Spring 2026
// This file is my first C++ Program

// To compile, open the "developer Command Prompt for VS 2022"
// navigate to this folder with 'cd' for 'change directory'
// use the command 'cl /EHsc filename.cpp' (in this case, it's main.cpp)
// and then type 'filename' to run the .exe this the "main"

#include <iostream>  // This is an in out stream, for sending text to the console. 
#include <string>   // For playerName

using namespace std;  // So we don't have to type "std::" all the time

// Here is where we start the program
int main() {
    // Variables declared at the top is best practice
    string playerName;  // Variables use camelCase

    // Ask the player for their name
    cout << "What is your name, player? "; 

    // Assign whatever the player types as the value of playerName
    cin >> playerName; 

    // greet the player by name
    cout << "Hello " << playerName << "." << endl;

    // user control+slash to comment out lines
    // cout << "Don't make me learn C++ please" << endl;   // cout = console out, endl = end line

    return 0;       // end the program
} 