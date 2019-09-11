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
#include <ctime>
#include <fstream>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    ofstream mathwks("mathWorksheet");

    double u;
    double v;
    double a,b,c,d;
    srand( unsigned(time(NULL)));

        u=(double)rand()/(RAND_MAX + 1)+0+(rand()%200)-100;
        v=(double)rand()/(RAND_MAX + 1)+0+(rand()%200)-100;
        a=u+v;
        b=u-v;
        c=u/v;
        d=u*v;

        mathwks >> a;


        mathwks.close();
    return 0;
}// signals the operating system that our program ended OK.
