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
#include <cmath>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main()
{
    double pricePerUnit,shipMin1,shipMin2,shipMin3,flatRate1,flatRate2,flatRate3,freeShipMin;
    double priceT=0;
    double shipPrice=0;
    double salesTax;
    double temp;
    double donationAmmount;
    char userAns;
    double numSprocket;
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

    priceT=numSprocket*pricePerUnit;

    if(priceT>=shipMin1 && priceT<=shipMin2)
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

    priceT=priceT+shipPrice;
    double priceT1=priceT+shipPrice;
    priceT=priceT+(priceT*(salesTax/100));
    priceT=priceT*100;
    priceT=round(priceT);
    priceT=priceT/100;


    if (abs(priceT)-abs(round(priceT)>.001))
    {
        cout<<"Would you like to donate and round up to the nearest value?"<<endl;
        cin>>userAns;
        userAns=toupper(userAns);
        if(userAns=='Y') {


            if (priceT < round(priceT)) {
                temp=priceT;
                priceT = round(priceT);
                donationAmmount=(round(priceT)-temp);
            } else if (priceT > round(priceT)) {
                temp=priceT;
                priceT = round(priceT) + 1;
                donationAmmount=(round(priceT))-temp;
            }
        }

        else
        {
            priceT=priceT;
            userAns='N';
        }


    }
    ofstream recipt ("recipt.txt");
    recipt << setfill('-') << setw(28) << "" << endl;
    recipt << setfill(' ')<<left<<"Sprockets-R-Us Order Recipt" <<endl;
    recipt << setfill('-') << setw(28) << "" << endl; // set the first line of ~ symbols
    recipt << setfill(' ')<<setw(20)<<left<<"Price Per Unit:" <<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<pricePerUnit<<endl;

    recipt << setfill(' ')<<left<<"Quantity Ordered:";
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
    if(userAns =='Y') {

        recipt << setfill(' ')<<setw(20)<<left<<"Donation Ammount"<<"$";
        recipt << right <<setw(7)<<fixed << setprecision(2)<<donationAmmount<<endl;
    }
    recipt << setfill('=') << setw(28) << "" << endl;
    recipt << setfill(' ')<<setw(20)<<left<<"Grand Total:"<<"$";
    recipt << right <<setw(7)<<fixed << setprecision(2)<<priceT<<endl;
    recipt << setfill('=') << setw(28) << "" << endl;
    return 0;
}// signals the operating system that our program ended OK.
