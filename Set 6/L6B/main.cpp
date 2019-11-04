/* CSCI 261 A5: Yahtzee
 *
 * Author: Allan Huntington
 *
 * This code converts polar to rectangular and vise versa
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>

#include <cmath>


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
void polarToCartesian (double r,double theta) // creates the first function, using r and theta
{
    double x1=r*cos(theta); // find the x and y
    double y1=r*sin(theta);
    cout <<"X: "<<x1<<" Y: "<<y1<<endl; // outputs the x and y to the user
}
void cartesianToPolar (double x,double y) // creates the second function
{
    double r1=sqrt((x*x)+(y*y)); // finds r and theta
    double theta1=atan(y/x);
    cout <<"R: "<<r1<<" Theta: "<<theta1<<endl; // outputs r and theta
}


int main () {
int userIn;
int userR;
int userTheta;
int userX;
int userY;
cout<< "(r, θ) -> (x, y) =1"<<endl; // ask the user which way they want to convert
cout<< "(x, y) -> (r, θ)=2"<<endl;
cin>> userIn;
if(userIn==1) // depending on the choice, get the use values and run the respective function.
{
    cout<<"Enter your R and Theta: ";
    cin>>userR>>userTheta;
    polarToCartesian(userR,userTheta);
}

else if(userIn==2)
{
        cout<<"Enter your X and Y: ";
        cin>>userX>>userY;
        cartesianToPolar(userX,userY);
}
    return 0;
}
