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
int main()
{
    double maxVal; // start all of the values needed for our calculations
    int numLines;
    double value;
    double sum1;
    double avg1;
    double avg2;
    double sum2=0;
    int userChoice;
    int counter=0;
    cout << "which file would you like to open?"<<endl; // as the user which file they want to open
    cout<<"1. Counter Controlled" <<endl;
    cout<<"2. Sentinel Controlled" <<endl;
    cin >> userChoice;
    if (userChoice==1) // if the open file one, follow the format to read the numbers
    {
        ifstream chart("counter_controlled.txt");

        if(chart.fail()) // if the chart does not open, show an error message
        {
            cout<<"failed to open file"<<endl;
            return -1;
        }
        cout << "The values in this file are"<<endl;
       chart >> numLines; // find the number of numbers in the file
        for(int i=0; i <numLines;i++)  // for the number of lines print each line and create a sum
        {
            chart >> value;
            sum1=value+sum1;
            cout <<value <<endl;
        }
        avg1=sum1/numLines; // print the average of numners
        cout<< "The average is: "<<avg1<<endl;

    }
    else if (userChoice ==2) // if they choose the second file follow that format
    {
        ifstream chart("sentinel_controlled.txt");


        if(chart.fail()) // if the chart does not open, show an error message
        {
            cout<<"failed to open file"<<endl;
            return -1;
        }

        while (9999+maxVal >= 10e-6) // while the maxVal is less then the max value, read the numbers
        {



                chart >> maxVal;

                if(maxVal >0) { // print and sum the numbers
                    cout << maxVal << endl;
                    sum2=maxVal+sum2;
                }
                counter++;

        }
        avg2=sum2/(counter-1); // calculate the average
        cout <<"There are " << counter-1<< " values in this file"<<endl; // print the numbers in the file
        cout<< "The average is: "<<avg2<<endl;

    }




    return 0; // signals the operating system that our program ended OK.
}
