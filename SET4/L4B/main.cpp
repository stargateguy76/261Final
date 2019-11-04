/* CSCI 261 Lab 2D
 *
 * Author: Allan Huntington
 * This program creates a multiplication table from two numbers showing the full table for any number between 2-11
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <time.h>

// We will (most of the time) use the standard library namespace in our programs
// CSCI 261 PL4: For Printer

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <ios>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>// For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;
int main()
{
    int num1=1; // initalize the number varibles
    int num2=1;
    int n=1;
    int count1[11] ={}; // make 2 arrays that can be the max length that the number can be
    int count2[11] ={};
    int product;
    bool run= true;
    cin>>num1;
    cin>>num2;
    while (num1<2 || num2 <2|| num1>10||num2>10) // if the number is valid, input it.
    {

        cin>>num1;
        cin>>num2;
        run=false;
    }

    run=true;
    if(run==true)
    {


        for(int a=0; a<=num1;a++) // fill the first array with values from 1 to num 1
        {
            count1[a]=a;
        }
        for(int b=0; b<=num2;b++) // fill the first array with values from 1 to num2
        {
            count2[b]=b;
        }

        cout<<setfill('.') << setw(2) << ""; // print the blank space for the first number (0) which is not shown

        for(int i=1;i<=num1;i++) // iterate from 1 to the length of num1 to print the top line
        {
            cout<<setfill('.')<<setw(4)<<right<<count1[i]; // print the numbers in the array
        }

        cout<< endl;  // print a new line
        cout<<setfill('.')<<setw(2)<<right<<count2[n]; // print the first number of the next collum.

        for(int i=1; i<=num1+1;i++) // loop for the length of num1
        {
            if(i==num1+1 && n<num2) { // if we get to the end of num 1, start a new line
                i=1;
                n++;
                cout<<endl;
                cout<<setfill('.')<<setw(2)<<right<<count2[n]; //print the num 2 to be multipled out for the next rows
            }

            product=count1[i]*count2[n]; // limit the extra 0 printed at the end
            if(product >0)
            {
                cout <<setfill('.')<<setw(4)<<right<<product;
            }

        }
        cout<<endl; // end the final line.


    }
    return 0; // signals the operating system that our program ended OK.
}
