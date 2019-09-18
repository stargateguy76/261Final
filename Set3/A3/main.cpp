/* CSCI 261 Lab 2C
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string, and then shows the winner of the game
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <ios>
#include <string>
#include <fstream>
#include <iomanip>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    double pricePerUnit,shipMin1,shipMin2,shipMin3,flatRate1,flatRate2,flatRate3,freeShipMin;
    int salesTax;
    int numSprocket;
    ifstream chart("product_public.txt");

if(chart.fail())
{
    cout<<"failed to open file"<<endl;
    return -1;
}
for( int i=1;i<=1;i++) {

    chart >> pricePerUnit;
    chart >> salesTax;
    chart >> shipMin1 >> flatRate1 >> shipMin2 >> flatRate2 >> shipMin3 >> flatRate3 >> freeShipMin;



}
cout<<"Welcome to Sprockets-R-Us!"<<endl;
cout<<"The cost of a single sprocket is: "<< setprecision(2)<<fixed<< pricePerUnit<<endl;
cout<<"How many sprockets do you wish to order?"<<endl;
cin>>numSprocket;

    chart.close();
cout<< "Thank you for your order of " <<numSprocket<< " sprockets!  One moment while we prepare your receipt..." <<endl;
    return 0;
}// signals the operating system that our program ended OK.
