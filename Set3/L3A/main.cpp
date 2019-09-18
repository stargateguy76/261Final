/* CSCI 261 Lab 3A
 *
 * Author: Allan Huntington
 * This Program outputs 2 random values, then adds subtracts and divides them.
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

        u=(double)rand()/(RAND_MAX + 1)+0+(rand()%200)-100; // create the two random values
        v=(double)rand()/(RAND_MAX + 1)+0+(rand()%200)-100;
        a=u+v; // do the arithmitc
        b=u-v;
        c=u/v;
        d=u*v;
    mathwks << u<<" + "<< v << " = "<< "?"<< endl; // prin the restults to the file
    mathwks << u<<" - "<< v << " = "<< "?"<< endl;
    mathwks << u<<" / "<< v << " = "<< "?"<< endl;
    mathwks << u<<" * "<< v << " = "<< "?"<< endl;





        mathwks.close();
    return 0;
}// signals the operating system that our program ended OK.
