/* CSCI 261 Lab 2C
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string.
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <time.h>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main() {
char input;
string compChoice[3]={"Rock","paper","Sciscors"};


int computerNumber;
srand(time(0));

cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl; // input a user choice for rock paper and scissors
cin >> input;
input=toupper(input);

if (input == 'R') // based off of the input, display them to the user as a string.
{
    cout <<"Player choose: Rock" <<endl;
}
if (input == 'S')
{
        cout <<"Player choose: Scissors" <<endl;
}
if (input == 'P')
{
        cout <<"Player choose: Paper" <<endl;
}

computerNumber=rand()%3;
cout <<"Copmuter choose: " << compChoice[computerNumber] << endl;


    return 0; // signals the operating system that our program ended OK.
}