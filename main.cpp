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
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main() {
    double side1=0;
    double side2=0;
    double side3=0;
    double valTemp=0;
    double tol=0.001;
    int sum;
    double area=0;
    double perimeter;
    double S;
    srand(time(0));
    rand();
    string Kind="N/a";
    cout << "Please enter your two sides" <<endl;
    cin >>side1 >> side2;

    sum=side1+side2;

    if (side1>side2)
    {
        valTemp=side1;
        side1=side2;
        side2=valTemp;

    }

    side3=rand() %(sum-int(side2)+1)+int(side2);
    perimeter=side1+side2+side3;
    S=perimeter/2;
    area=sqrt(S*((S-side1)*(S-side2)*(S-side3)));




    if (fabs(pow(side1,2) + pow(side2,2) - pow(side3,2)) <=tol)
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
cout <<"you have a triangle with sides:"<< side1 <<" " << side2<<" " <<side3 <<endl;
cout << "You have a " << Kind << " triangle"<<endl;
cout << "the area of the triangle is: " << area <<endl;
cout<< "the perimeter of the triangle is : " <<perimeter <<endl;
    return 0; // signals the operating system that our program ended OK.
}