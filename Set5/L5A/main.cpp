/* CSCI 261 Lab 5A
 *
 * Author: Allan Huntington
 * This program asks the user for number input and then displays them back to the user
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <time.h>




#include <string>
#include <fstream>
#include <iomanip>
#include <cmath> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;



int main() {
    int userNum[15];
    cout << "Hey! Witness my first array mojo!\n"
            "Enter 15 numbers and I will tell you what they are." << endl;
    for (int i = 1; i <= 15; i++) {
        cout << "Number " << i << ":";
        cin >> userNum[i-1];
        cout << endl;
    }
    cout << "So awesome!" << endl;

    cout << "The numbers are: ";
    for (int i = 1; i <= 15; i++)
    {
        cout << userNum[i-1];
        cout<<" ";
    }
    cout<< endl;


    return 0; // signals the operating system that our program ended OK.
}
