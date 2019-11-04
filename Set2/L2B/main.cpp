/* CSCI 261 Lab 2b
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output
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

int computerNumber;
srand(time(0));

cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" <<p endl; // as the user for thier input
cin >> input;

computerNumber=rand()%3; // randomly generate a computer choice
cout <<"Player choose: " << input <<endl;
cout <<"Copmuter choose: " << computerNumber << endl; // display both choices


    return 0; // signals the operating system that our program ended OK.
}