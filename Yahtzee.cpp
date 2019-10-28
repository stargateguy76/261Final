//
// Created by Allan Huntington on 2019-10-27.
//
#include <iostream>
#include "Yahtzee.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include <array>
using namespace std;
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
int saveNums(char y)
{
    int num;
    if(y=='N')
    {
        num=rollDie();
    }
    return num;
}


int scoreOnes( int die1, int die2, int die3, int die4, int die5 ) {
    int score = 0;
    if (die1 == 1) {
        ++score;
    }
    if (die2 == 1) {
        ++score;
    }
    if (die3 == 1) {
        ++score;
    }
    if (die4 == 1) {
        ++score;
    }
    if (die5 == 1) {
        ++score;
    }
    return score;
}

int scoreTwos(int die1, int die2, int die3, int die4, int die5){
    int count = 0;
    int dieValues[5] = {die1, die2, die3, die4, die5};
    for(int i=0; i < 5; i++){
        if(dieValues[i] == 2){
            count++;
        }
    }
    return (count * 2);
}



int scoreThrees( int die1, int die2, int die3, int die4, int die5 ) {
    int diceArray[5] = {die1, die2, die3, die4, die5};
    int threesSum = 0;
    for (int i = 0; i < 6; ++i) {
        if (diceArray[i] == 3) {
            threesSum += 3;
        }
    }
    return threesSum;
}

int scoreFours( int die1, int die2, int die3, int die4, int die5 ) {
    int die[5] {die1, die2, die3, die4, die5};
    int numFours = 0;
    for (int i = 0; i < 5; ++i) {
        if (die[i] == 4) {
            numFours += 4;
        }
    }
    return numFours;
}

int scoreFives( int die1, int die2, int die3, int die4, int die5 ) {
    int count = 0;
    int dice[5] = {die1, die2, die3, die4, die5};
    for (int i = 0; i < 5; i++) {
        if (dice[i] == 5) {
            count++;
        }
    }
    return (count * 5);
}

int scoreSixes( int die1, int die2, int die3, int die4, int die5 ) {
    int count = 0;
    int diceValues[5] = {die1, die2, die3, die4, die5};
    for (int i = 0; i < 5; i++) {
        if (diceValues[i] == 6) {
            count++;
        }
    }
    return (count * 6);
}

int scoreThreeKind( int die1, int die2, int die3, int die4, int die5 ) {

    int countMatchFromDie1 = 1;
    int countMatchFromDie2 = 1;
    int die[5] = {die1, die2, die3, die4, die5};
    for (int i = 0; i < 4; ++i) {
        if (die[0] == die[i+1]) {
            countMatchFromDie1++;
        }
        if (die[1] == die[i+2]) {
            countMatchFromDie2++;
        }
    }
    if ((countMatchFromDie1 >= 3) || (countMatchFromDie2 >= 4)){
        return (die1+die2+die3+die4+die5);
    } else {
        return 0;
    }
}


int scoreFourKind( int die1, int die2, int die3, int die4, int die5 ) {

    int countMatchFromDie1 = 1;
    int countMatchFromDie2 = 1;
    int die[5] = {die1, die2, die3, die4, die5};
    for (int i = 0; i < 4; ++i) {
        if (die[0] == die[i+1])  {
            countMatchFromDie1++;
        }
        if (die[1] == die[i+2]) {
            countMatchFromDie2++;
        }
    }
    if ((countMatchFromDie1 >= 4) || (countMatchFromDie2 >= 4)){
        return (die1+die2+die3+die4+die5);
    } else {
        return 0;
    }
}


int scoreFullHouse( int die1, int die2, int die3, int die4, int die5 ) {
    int die[5] = {die1, die2, die3, die4, die5};
    int numOnes = 0;
    int numTwos = 0;
    int numThrees = 0;
    int numFours = 0;
    int numFives = 0;
    int numSixes = 0;
    for (int i = 0; i < 5; i++) {
        if (die[i] == 1) {
            numOnes += 1;
        } else if (die[i] == 2) {
            numTwos += 1;
        } else if (die[i] == 3) {
            numThrees += 1;
        } else if (die[i] == 4) {
            numFours += 1;
        } else if (die[i] == 5) {
            numFives += 1;
        } else if (die[i] == 6) {
            numSixes += 1;
        }
    }
    int nums[6]= {numOnes, numTwos, numThrees, numFours, numFives, numSixes};
    bool twoOfSame;
    bool threeOfSame;
    for (int j= 0; j < 6; j++) {

        if (nums[j] == 3) {
            threeOfSame = true;
        }
        else if (nums[j] == 2) {
            twoOfSame = true;
        }
    }
    if ((twoOfSame == true) && (threeOfSame == true)) {
        return 25;
    }
    else {
        return 0;
    }
}


bool isSmallStraight(int die1, int die2, int die3, int die4, int die5) {
    vector<int> smallS = {die1, die2, die3, die4, die5};
    int ones = 0;
    int twos = 0;
    int threes = 0;
    int fours = 0;
    int fives = 0;
    int sixes = 0;

    for (int i = 0; i < 5; i++) {
        if (smallS.at(i) == 1) {
            ones++;
        } else if (smallS.at(i) == 2) {
            twos++;
        } else if (smallS.at(i) == 3) {
            threes++;
        } else if (smallS.at(i) == 4) {
            fours++;
        } else if (smallS.at(i) == 5) {
            fives++;
        } else {
            sixes++;
        }
    }


    if (ones >= 1 && twos >= 1 && threes >= 1 && fours >= 1) {
        return true;
    }

    if (twos >= 1 && threes >= 1 && fours >= 1 && fives >= 1) {
        return true;
    }

    if (threes >= 1 && fours >= 1 && fives >= 1 && sixes >= 1) {
        return true;
    } else {
        return 0;
    }
}


int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5){
    if(isSmallStraight(die1, die2, die3, die4, die5)){
        return 30;
    }else{
        return 0;
    }
}

bool isLargeStraight( int die1, int die2, int die3, int die4, int die5 ) {
    int product;
    product = die1 * die2 * die3 * die4 * die5;
    if (product == 120){
        return true;
    }
    else if (product == 720){
        return true;
    }
    else{
        return false;
    }
}


int scoreLargeStraight( int die1, int die2, int die3, int die4, int die5 ) {
    if (isLargeStraight(die1, die2, die3, die4, die5) == true){
        return 40;
    }
    else{
        return 0;
    }
}


int Chance(int die1, int die2, int die3, int die4, int die5){
    int chanceScore;
    chanceScore = die1 + die2 + die3 + die4 + die5;
    return chanceScore;
}

bool isYahtzee( int die1, int die2, int die3, int die4, int die5 ) {
    if((die1 == die2) && (die1 == die3) && (die1 == die4) && (die1 == die5)){
        return true;
    }
    else{
        return false;
    }
}

int scoreYahtzee( int die1, int die2, int die3, int die4, int die5 ) {
    int score = 0;
    if(isYahtzee(die1,die2,die3,die4,die5) == true){
        score = 50;
    }
    return score;
}