/* CSCI 261 Lab 2D
 *
 * Author: Allan Huntington
 * THis is a basic rock paper scissors program that askes for user input and randomly generates a computer output, and then shows the answer as a string, and then shows the winner of the game
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
 int num1=1;
 int num2=1;
 int n=1;
 int count1[12] ={};
 int count2[12] ={};
 int product;
 bool run;
cin>>num1;
cin>>num2;
while(num1>1 &&num2>2 && num1<11 && num2 <11)
{

  cin>>num1;
  cin>>num2;
}
else {
    run=true;
}
if(run==true)
{


for(int a=0; a<=num1;a++)
{
    count1[a]=a;
}
for(int b=0; b<=num2;b++)
{
    count2[b]=b;
}

cout<<setfill('.') << setw(2) << "";

for(int i=1;i<=num1;i++)
{

    cout<<setfill('.')<<setw(4)<<right<<count1[i];
}

cout<< endl;
cout<<setfill('.')<<setw(2)<<right<<count2[n];

for(int i=1; i<=num1+1;i++)
{
    if(i==num1+1 && n<num2) {
        i=1;
        n++;
        cout<<endl;
        cout<<setfill('.')<<setw(2)<<right<<count2[n];
    }

    product=count1[i]*count2[n];
    if(product >0)
    {
        cout <<setfill('.')<<setw(4)<<right<<product;
    }

}
cout<<endl;


}
    return 0; // signals the operating system that our program ended OK.
}
