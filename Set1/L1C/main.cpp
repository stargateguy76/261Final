/* CSCI 261 Lab 1C
 *
 * Author: Allan Huntington
 *
 * Calculate the volulme of a prisim, by asking for side lengths then calculating.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <cmath>// For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


int main() {

int var =10; // intitalize all of the varibles
int base;
int width;
int height;
int volume;
double radius;
double area;
double const PI = 3.1415;
cout << " please enter the with, base and height of your prism (in inches)" << endl; // ask the user to the sides of their prisim
    cin >> width;
    cin >> base;
    cin >>  height;
volume=base*width*height; //calculate the volume

cout << "the volume of your prism is: " <<volume  <<" cubic inches"<< endl; // output the volume

cout << "please enter the radius of your circle (in inches)" << endl;
cin >> radius;
area = PI*pow(radius,2);

cout << "the area of a circle with the radius " << radius <<" is: " << area << "square inches" <<endl;



    return 0; // signals the operating system that our program ended OK.
}