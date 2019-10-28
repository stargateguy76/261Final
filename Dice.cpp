//
// Created by Allan Huntington on 2019-10-28.
//
#include <iostream>
#include "Yahtzee.h"

#include <stdlib.h>



using namespace std;
#include "Dice.h"

int rollDie(){
    int roll;

    roll=((rand()%5)+1);
    return roll;
}

int rollDice(int x[])
{

    for (int i = 0; i < 5; i++)
    {
        x[i] = rollDie();
    }
}

int printHand(int z[])
{
    cout<<"Your Hand is: ";

    for(int i=0;i<5;i++)
    {
        if(z[i]<7) {

            cout << z[i] << " ";
        }
    }
    cout<<endl;
}

