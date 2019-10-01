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
    int userIn; // decare all of the varibles to be uesed in the program
    char guess[5];
    int low;
    int high;
    int realNum;
    int count=0;
    const int TOO_CLOSE=5; // set the constants for the difficulty of the game
    const int TOO_FAR=25;
    const int MIN_RANGE=100;


    bool run= true;
    srand(time(0)); // declare the random number generator


    cout << "Enter the lowest number: "; // enter the highest and lower numbers
    cin >> low;
    cout << endl;

    cout << "Enter the highest number: ";
    cin >> high;
    cout << endl;
    while (high - low < MIN_RANGE) { // make sure the difference between the number is at least 100

    cout << "High number must be at least 100 more than the low number." << endl;

        cout << "Enter the highest number: ";
        cin >> high;
        cout << endl;

}
    realNum=rand()%(high-low) +low; // set the real number using the rand() function




 while (run==true) { // while the user does not guess the number, run the loop
     cout << endl;
     cout << "Pick a number Between " << low << " and " << high << ": ";
     cin >> guess;

     for (int i = 0; i < 1; i++) { // check the user input for characters
         if (isdigit(guess[i])) {
             userIn = stoi(guess);
         } else {
             userIn = 0;

         }
     }



     if (userIn == realNum) { // if they guess the number, exit the loop
         run = false;
     }

     if (abs(userIn - realNum) < TOO_CLOSE && userIn < realNum) { //statements for each case depending on the number the user inputted.
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
count++;





 }
 cout<<"Congratulations the number was: "<<realNum <<endl; // print the real number and total guesses to get to the answer
 cout<<" You guessed the number in " <<count <<" tries"<<endl;

    return 0; // signals the operating system that our program ended OK.
}
