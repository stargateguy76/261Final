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

int var =10;
int base;
int width;
int height;
int volume;
double radius;
double area;
double const PI = 3.1415;
cout << " please enter the with, base and height of your prism (in inches)" << endl;
    cin >> width;
    cin >> base;
    cin >>  height;
volume=base*width*height;

cout << "the volume of your prism is: " <<volume  <<" cubic inches"<< endl;

cout << "please enter the radius of your circle (in inches)" << endl;
cin >> radius;
area = PI*pow(radius,2);

cout << "the area of a circle with the radius " << radius <<" is: " << area << "square inches" <<endl;



    return 0; // signals the operating system that our program ended OK.
}