/* CSCI 261 Lab 2C
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string, and then shows the winner of the game
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <iostream>
#include <ios>
#include <iomanip>
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



    for( int i=1;i<=4;i++) // run this loop 4 times, to input each line of the code
    {
        mathwks>> u;  // import one line formatted with data type correctly
        mathwks>> mathSign;
        mathwks>> v;
        mathwks>> equalSign;
        mathwks>> questionMark;
        if(i==1) // set the math operaters based off of the for loop
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
        cout << setfill('~') << setw(28) << "" << endl; // set the first line of ~ symbols
        cout << setfill(' ')<<fixed << setprecision(3)<<setw(8)<<left<<u<<mathSign; // set the length and the width of each line and number, while filling the blanks with spaces
        cout <<" "<< setw(8)<< left<< v << equalSign;
        cout <<setw(9) << right << ans << endl;


    }
    cout << setfill('~') << setw(28) << "" << endl; // prints and extra line of ~ at the end of the output.

    mathwks.close();
    return 0;
}// signals the operating system that our program ended OK.
