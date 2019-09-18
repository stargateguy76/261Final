/* CSCI 261 Assignment 3a
 *
 * Author: Allan Huntington
 * This program creates a receipt from an order form, and formats and prints the output correctly to a seperate text file
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <ios>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    double pricePerUnit,shipMin1,shipMin2,shipMin3,flatRate1,flatRate2,flatRate3,freeShipMin; // create doubles for all of the numeric inputs
    double priceT=0;
    double shipPrice=0;
    double salesTax;
    double temp;
    double donationAmmount;
    char userAns; // create a char for the user input for a donation
    double numSprocket;
    ifstream chart("product_public.txt"); // open the product public .txt files

    if(chart.fail()) // if the chart does not open, show an error message
    {
        cout<<"failed to open file"<<endl;
        return -1;
    }
    for( int i=1;i<=1;i++) { // read the numbers from the opened file

        chart >> pricePerUnit;
        chart >> salesTax;
        chart >> shipMin1 >> flatRate1 >> shipMin2 >> flatRate2 >> shipMin3 >> flatRate3 >> freeShipMin;



    }

    cout<<"Welcome to Sprockets-R-Us!"<<endl; //format the user input for the order form and ask for the number of sprockets
    cout<<"The cost of a single sprocket is: "<< setprecision(2)<<fixed<< pricePerUnit<<endl;
    cout<<"How many sprockets do you wish to order?"<<endl;
    cin>>numSprocket;

    chart.close();
    cout<< "Thank you for your order of " <<numSprocket<< " sprockets!  One moment while we prepare your receipt..." <<endl;

    priceT=numSprocket*pricePerUnit; //set the inital price of the sprockets

    if(priceT>=shipMin1 && priceT<=shipMin2)  // add the shipping based on the first sub total
    {
        shipPrice=flatRate1;
    }
    else if (priceT>=shipMin2 && priceT<=shipMin3)
    {
        shipPrice=flatRate2;
    }
    else if (priceT>=shipMin3 && priceT<=freeShipMin)
    {
        shipPrice=flatRate3;
    }
    else if(priceT>-freeShipMin)
    {
        shipPrice=0;
    }
    else
    {
        shipPrice=flatRate1;
    }

    priceT=priceT+shipPrice; //add the shipping price to the subtotal
    double priceT1=priceT+shipPrice; // remeber this price for a later call
    priceT=priceT+(priceT*(salesTax/100)); // add the sales tax to the price
    priceT=priceT*100; // multiply by 100 to determine if we have a penny remainder
    priceT=round(priceT); // if we have a fraction of a penny, round the number
    priceT=priceT/100; // reformat the price


    if (abs(priceT)-abs(round(priceT)>.001))// if the total cost is not an even dollar ammount, ask to donate up to the value
    {
        cout<<"Would you like to donate and round up to the nearest value?"<<endl;
        cin>>userAns;
        userAns=toupper(userAns); //compensate for lowercase and upercase Y
        if(userAns=='Y') {


            if (priceT < round(priceT)) { // if the price is lower then the rounded price, set the price to the rounded ammount
                temp=priceT;
                priceT = round(priceT);
                donationAmmount=(round(priceT)-temp);
            } else if (priceT > round(priceT)) { // if the price is higher, set it to the rounded number +1
                temp=priceT;
                priceT = round(priceT) + 1;
                donationAmmount=(round(priceT))-temp;
            }
        }

        else // if they did not want a donation show that.
        {
            priceT=priceT;
            userAns='N';
        }


    }
    ofstream recipt ("recipt.txt"); // format the receipt output.
    recipt << setfill('-') << setw(28) << "" << endl; // set a line of - 28 long
    recipt << setfill(' ')<<left<<"Sprockets-R-Us Order Recipt" <<endl;  // print the header
    recipt << setfill('-') << setw(28) << "" << endl; // set the second line
    recipt << setfill(' ')<<setw(20)<<left<<"Price Per Unit:" <<"$"; // set the left side of the table using a width of 20, and the $ and text
    recipt << right <<setw(7)<<fixed << setprecision(2)<<pricePerUnit<<endl; // set the right side with theh price and remaning length of the number

    recipt << setfill(' ')<<left<<"Quantity Ordered:"; // repeat from above untill all values are printed
    recipt << right <<setw(10)<<fixed << setprecision(2)<<numSprocket<<endl;

    recipt << setfill(' ')<<setw(20)<<left<<"Unit Subtotal"<<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<pricePerUnit*numSprocket<<endl;

    recipt << setfill('-') << setw(28) << "" << endl;
    recipt << setfill(' ')<<setw(20)<<left<<"Shipping Fee:"<<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<shipPrice<<endl;

    recipt << setfill('-') << setw(28) << "" << endl;
    recipt << setfill(' ')<<left<<"Sales Tax (" << salesTax<<setw(5)<< "%)"<<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<priceT1*(salesTax/100)<<endl;

    recipt << setfill('-') << setw(28) << "" << endl;
    recipt << setfill(' ')<<left<<"Donation?";
    recipt << right <<setw(19)<<fixed << setprecision(2)<<userAns<<endl;
    if(userAns =='Y') { // if the user makes a donation, be sure to add the line that shows the donation ammmount.

        recipt << setfill(' ')<<setw(20)<<left<<"Donation Ammount"<<"$";
        recipt << right <<setw(7)<<fixed << setprecision(2)<<donationAmmount<<endl;
    }
    recipt << setfill('=') << setw(28) << "" << endl;
    recipt << setfill(' ')<<setw(20)<<left<<"Grand Total:"<<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<priceT<<endl;
    recipt << setfill('=') << setw(28) << "" << endl;
    return 0;
}// signals the operating system that our program ended OK.
