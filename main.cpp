/* CSCI 261 Lab 1B: Intro to ACSI art
 *
 * Author: Allan Huntington
 *
 * More complete description here...
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <cmath>// For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants or global variables below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

    double speed = 63.5;
    int age = 19;
    double gpa =3.5;


cout << "                  __ooooooooo__\n"
        "              oOOOOOOOOOOOOOOOOOOOOOo\n"
        "          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
        "       oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
        "     oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
        "   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
        "  oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo\n"
        " oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo\n"
        " oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo\n"
        "oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
        "oOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOo\n"
        "oOOOOOO OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO OOOOOOo\n"
        " *OOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOO*\n"
        " *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*\n"
        "  *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*\n"
        "   *OOOOOOo  *OOOOOOOOOOOOOOOOOOOOOOO*  oOOOOOO*\n"
        "     *OOOOOOOo  *OOOOOOOOOOOOOOOOO*  oOOOOOOO*\n"
        "       *OOOOOOOOo  *OOOOOOOOOOO*  oOOOOOOOO*      \n"
        "          *OOOOOOOOo           oOOOOOOOO*      \n"
        "              *OOOOOOOOOOOOOOOOOOOOO*          \n"
        "                   \"\"ooooooooo\"\"" << endl;

cout <<"Hello world!"<<endl;
cout <<"I am: "<< age << " years old" << endl;
cout <<"The fastsest ive gone on a bike is : " << speed << " mph" <<endl;
cout <<"My gpa is: " << gpa <<endl;
cout <<"Goodbye!"<<endl;


    return 0; // signals the operating system that our program ended OK.
}