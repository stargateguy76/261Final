/* CSCI 261 Lab 2C
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string, and then shows the winner of the game
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <string>
#include <fstream>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    double u;
    double v;
    string equalSign;
    string plusSign;
    string questionMark;

    ifstream mathwks("mathWorksheet");
    mathwks>> u;
    mathwks>> plusSign;
    mathwks>> v;


    cout << u<<" + "<< v << " = "<< u+v<< endl;
    cout << u<<" - "<< v << " = "<< u-v<< endl;
    cout << u<<" / "<< v << " = "<< u/v<< endl;
    cout << u<<" * "<< v << " = "<< u*v<< endl;



        mathwks.close();
    return 0;
}// signals the operating system that our program ended OK.
