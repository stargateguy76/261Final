/* CSCI 261 A5: Yahtzee
 *
 * Author: Allan Huntington
 *
 * This code converts polar to rectangular and vise versa
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include "iomanip"

#include <cmath>
#include "fstream"


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;


int main () {
    double xPos[3526];
    double yPos[3526];
    double zPos[3526];
    double bright[3526];
    double draper[3526];
    double harvard[3526];
    double WIDTH=640;
    int HEIGHT=640;
    ifstream starIn("stars.txt");
    ofstream starOut("modifiedStars.txt");

    if(starIn.fail()) // if the chart does not open, show an error message
    {
        cout<<"failed to open file"<<endl;
        return -1;
    }
    for(int i =0;i<3526; i++)
    {
        starIn>>xPos[i];
        starIn>>yPos[i];
        starIn>>zPos[i];
        starIn>>bright[i];
        starIn>>draper[i];
        starIn>>harvard[i];
    }

    for (int i=0;i<3526;i++)
    {
        if(bright[i]<8.0 && bright[i]>0.0)
        {
            int xPixel = (int)( ( xPos[i] + 1 ) * WIDTH / 2 );
            int yPixel = (int)( ( -yPos[i] + 1 ) * HEIGHT / 2 );
            starOut<<xPixel<< '\t'<<yPixel <<'\t'<<bright[i] <<endl;
        }
    }


    return 0;

}
