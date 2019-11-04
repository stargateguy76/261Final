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

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

int main() {
char input;
int win;
string compChoice[3]={"Rock","paper","Sciscors"};
string userChoice[3]={"Rock","paper","Sciscors"};


int computerNumber;
srand(time(0));

cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R or S)" << endl; // ask the user for their choice of rock paper or scissors
cin >> input;
input=toupper(input);

if (input == 'R') // if the user chooses rock, paper or scissors, print thier choice and set the win integer to is respective value
{
    cout <<"Player choose: Rock" <<endl;
    win =0;

}
if (input == 'S')
{
        cout <<"Player choose: Scissors" <<endl;
        win=2;

}
if (input == 'P')
{
        cout <<"Player choose: Paper" <<endl;
        win=1;

}

    computerNumber=rand()%3; // randomly generate a choice for the computer as a number 0,1,2
    cout <<"Computer choose: " << compChoice[computerNumber]  << endl; // call that number as an index value for a string array carrying rock paper or scissors

if (computerNumber==win) // run comparisons between the computer choice and the user choice to determine who wins.
{
    cout <<"its a tie!" <<endl;
}
if ((computerNumber==0 && win==1)  || (computerNumber==1 && win==2) ||(computerNumber==2 && win==0) )
{
        cout <<"user wins" <<endl;
}
if ((computerNumber==1 && win== 0)  || (computerNumber==2 && win==1) ||(computerNumber==1 && win==2) )
{
        cout <<"computer wins" <<endl;
}




    return 0; // signals the operating system that our program ended OK.
}