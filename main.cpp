/* CSCI 261 Lab 2C
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string, and then shows the winner of the game
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>

#include <string>
#include <fstream>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    double u;
    double v;
    int i;
    double ans;
    string equalSign;
    string mathSign;
    string questionMark;

    ifstream mathwks("mathWorksheet");



    for( int i=1;i<=4;i++)
    {
        mathwks>> u;
        mathwks>> mathSign;
        mathwks>> v;
        mathwks>> equalSign;
        mathwks>> questionMark;
        if(i==1)
        {
            ans=u+v;
        }
        else if(i==2)
        {
            ans=u-v;
        }
        else if(i==3)
        {
            ans=u/v;
        }
        else if(i==4)
        {
            ans=u*v;
        }

        cout << u<< " "<<mathSign << " "<< v << " "<< equalSign << " " << ans<< endl;
    }


        mathwks.close();
    return 0;
}// signals the operating system that our program ended OK.
