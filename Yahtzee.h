//
// Created by Allan Huntington on 2019-10-27.
//
#include <string>;
#ifndef SET1_YAHTZEE_H
#define SET1_YAHTZEE_H

int rollDie();
int printHand(int x[]);
int rollDice(int x[]);
int saveNums(int x, char y);
int add (int x, int y);
int scoreOnes( int die1, int die2, int die3, int die4, int die5 );
int scoreTwos(int die1, int die2, int die3, int die4, int die5);
int scoreThrees( int die1, int die2, int die3, int die4, int die5 );
int scoreFours( int die1, int die2, int die3, int die4, int die5 );
int scoreFives( int die1, int die2, int die3, int die4, int die5 );
int scoreSixes( int die1, int die2, int die3, int die4, int die5 );
int scoreThreeKind( int die1, int die2, int die3, int die4, int die5 );
int scoreFourKind( int die1, int die2, int die3, int die4, int die5 );
int scoreFullHouse( int die1, int die2, int die3, int die4, int die5 );
bool isSmallStraight(int die1, int die2, int die3, int die4, int die5);
int scoreSmallStraight(int die1, int die2, int die3, int die4, int die5);
bool isLargeStraight( int die1, int die2, int die3, int die4, int die5 );
int scoreLargeStraight( int die1, int die2, int die3, int die4, int die5 );
int Chance(int die1, int die2, int die3, int die4, int die5);
int scoreYahtzee( int die1, int die2, int die3, int die4, int die5 );
bool isYahtzee( int die1, int die2, int die3, int die4, int die5 );
#endif //SET1_YAHTZEE_H
