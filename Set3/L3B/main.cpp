/* CSCI 261 Lab 3b
 *
 * Author: Allan Huntington
 *  This program reads the mathworksheet file and then prints its results to the user
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

    ifstream mathwks("mathWorksheet"); // open and read the file
    mathwks>> u;
    mathwks>> plusSign;
    mathwks>> v;


    cout << u<<" + "<< v << " = "<< u+v<< endl; // print the file results
    cout << u<<" - "<< v << " = "<< u-v<< endl;
    cout << u<<" / "<< v << " = "<< u/v<< endl;
    cout << u<<" * "<< v << " = "<< u*v<< endl;



        mathwks.close(); // close the file
    return 0;
}// signals the operating system that our program ended OK.
