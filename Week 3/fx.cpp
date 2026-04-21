// Keira Vilaysing Coding 1 Spring 2026
// Functions

/* Block Comment*/
/*
    functions
        returnType FunctionName (input parameters) {code}
        passing by value
        passing by reference
*/

#include <iostream>
#include <string>
#include <cstdlib>  // for srand() and rand()
#include <ctime>    // for time
#include <vector>

using namespace std;

// declaring and defining a new function
// the return type is void, which means it returns nothing 
// the name of the function is "sayHello"
// the input parameters go in the parenthesis... this function doesnt have any
// then the code goes between curly braces {}!
void sayHello() {
    cout << "Hello!\n";
}

void doAddition(int firstNum, int secondNum) {
    cout << "Our first number is " << firstNum << ".\n";
    cout << "Our second number is " << secondNum << ".\n";
    cout << "Together they make " << firstNum + secondNum << ".\n";
}

// dont forget to include <cstdlib> and <ctime>
// this function will return an integer
int dieRoll(int sides = 6) {
    return rand() % sides +1;
}

//Create a function
// return type is bool
// name is askYesNo
// no input parameters (for now)
bool askYesNo (string question = "Do you want to keep playing?") {
    while(true) {
        cout << question << "(yes/no)\n";
        string input;
        getline(cin, input);

        if(input == "yes") {
            cout << "Okay! Keep Playing.\n";
            return true;
        }
        else if(input == "no") {
            return false;
        }
        else {
            cout << "I do not understand. Please type 'yes' or no.\n";
        }
    }
}

// Variable scope
// global variables
// passing by reference
// #include <vector>

void showVec(vector<string>& vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
}

// create a reference with an ampersand next to the variable type.
// int& number; or string& name;

//references let us edit the original.
void addStringToVec(vector<string>& vec) {
    cout << "What name would you like to add?\n";
    string input;
    getline(cin, input);

    vec.push_back(input);

    //  showVec(vec); //the added name exists here
}


int main() {
    srand(time(0));     // seed the random number generator
    vector<string> names = {"Finn", "Jake", "BMO", "Princess Bubblegum"};

    cout << "Finally, functions!\n";

    // calling the showVec() function and sending it our vector of names
    showVec(names);

    addStringToVec(names);  // try to add a string to our names vector

    showVec(names);     // notice that it doesnt add the string to our names vector.

    sayHello(); 

    doAddition(14, 8);

    cout << "Let's roll the dice! Our first number is " << dieRoll(6) << ".\n";

    doAddition(dieRoll(20), dieRoll(20));
    doAddition(dieRoll(), dieRoll(222));

    // call the askYesNo() function, and it will return true or false.
    if(askYesNo()) {
        cout << "Let's start the next Level\n";
    }
    else {
        cout << "Thanks for playing!\n";
        return 0;
    }
    if(askYesNo("Do you like watermelons?")) {
        cout << "Hey, yeah, they're yummy!\n";
    }
    else {
        cout << "Me too, it's a texture thing.\n";
    }


    return 0;
}