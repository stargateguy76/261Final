/* CSCI 261 Lab 2D
 *
 * Author: Allan Huntington
 * this program reads and prints the numbers in a file, following different ways to know when to stop reading the numbers
 * then calculating the average
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <time.h>




#include <string>
#include <fstream>
#include <iomanip>
#include <cmath> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;



int main() {
    int userIn;
    char guess[5];
    int low;
    int high;
    int realNum;
    const int TOO_CLOSE=5;
    const int TOO_FAR=25;
    const int MIN_RANGE=100;


    bool run= true;
    srand(time(0));


    cout << "Enter the lowest number: ";
    cin >> low;
    cout << endl;

    cout << "Enter the highest number: ";
    cin >> high;
    cout << endl;
    while (high - low < MIN_RANGE) {

    cout << "High number must be at least 100 more than the low number." << endl;

        cout << "Enter the highest number: ";
        cin >> high;
        cout << endl;

}
    realNum=rand()%(high-low) +low;




 while (run==true) {

     cout << "Pick a number Between " << low << " and " << high << ": ";
     cin >> guess;

     for (int i = 0; i < 2; i++) {
         if (isdigit(guess[i])) {
             userIn = stoi(guess);
         } else {
             userIn = 0;

         }
     }

     cout << endl;

     if (userIn == realNum) {
         run = false;
     }

     if (abs(userIn - realNum) < TOO_CLOSE && userIn < realNum) {
         cout << "Too low! Oooh you're close!" << endl;
     }
     else if (userIn==0)
     {
         cout<<"Please pick a number"<<endl;
     }
     else if(userIn>high || userIn <low)
     {
         cout << "Please select a number in the range" << endl;
     }

     else if(abs(userIn-realNum)>TOO_FAR && userIn <realNum)
     {
         cout<<"Too low! Not even close!"<<endl;
     }
     else if(userIn <realNum)
     {
         cout<<"Too low"<<endl;
     }

     else if(abs(userIn-realNum) <TOO_CLOSE && userIn>realNum)
     {
         cout<<"Too high! Oooh you're close!"<<endl;
     }
     else if(abs(userIn-realNum)>TOO_FAR && userIn>realNum)
     {
         cout<<"Too high! Not even close!"<<endl;
     }
     else if( userIn >realNum)
     {
         cout<<"To high"<<endl;
     }






 }
 cout<<"Congratulations the number was: "<<realNum <<endl;
    return 0; // signals the operating system that our program ended OK.
}
