/* CSCI 261 Assignment 2a
 *
 * Author: Allan Huntington
 *  THis is a program that asks the user for 2 sides of a triangle, then finds the third side and displays the kind of triangle
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <ctime>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main() {
    double side1=0; // intialise all of the varibles we will use in the program and keep them as doubles for various size triangles
    double side2=0;
    double side3=0;
    double valTemp=0;
    double tol=0.001;
    int sum;
    double area=0;
    double perimeter;
    double S;
    srand(time(0)); // intialize the random timer
    rand();
    string Kind="N/a";
    cout << "Please enter your two sides" <<endl; // as the user for the first 2 sides of the triangle
    cin >>side1 >> side2;

    sum=side1+side2; // find the integer sum of the two sides

    if (side1>side2) // if side 1 is bigger then side two, reorder the numbers so a side 1 is the smallest and side 3 is the largest
    {
        valTemp=side1;
        side1=side2;
        side2=valTemp;

    }

    side3=rand() %(sum-int(side2)+1)+int(side2); // find the randomly generated third side
    perimeter=side1+side2+side3; // find the perimeter and area of the triangle using herons formula
    S=perimeter/2;
    area=sqrt(S*((S-side1)*(S-side2)*(S-side3)));




        if (fabs(pow(side1,2) + pow(side2,2) - pow(side3,2)) <=tol) // compare the values to determine the kind of triangle
        {
            Kind="Right";
        }
        else if(pow(side1,2)+pow(side2,2)>pow(side3,2))
        {
        Kind="Acute";
        }
        else{
        Kind = "Obtuse";
        }
    cout <<"you have a triangle with sides:"<< side1 <<" " << side2<<" " <<side3 <<endl; //print all of the calculated information.
    cout << "You have a " << Kind << " triangle"<<endl;
    cout << "the area of the triangle is: " << area <<endl;
    cout<< "the perimeter of the triangle is : " <<perimeter <<endl;
        return 0; // signals the operating system that our program ended OK.
}