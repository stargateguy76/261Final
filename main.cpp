/* CSCI 261 A5: PPM Image Editor
 *
 * Author: Allan Huntington
 *
 * this code inputs an image as a vector and the mofidies the pixel colors to change the image
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <time.h>
#include <vector>
#include <string>
#include <fstream>


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

#include "Yahtzee.h"


int main () {
    srand(time(NULL));
    const int HAND_SIZE = 5;
    int count=3;
    int score;
    int die1;
    int die2;
    int die3;
    int die4;
    int die5;
    int userIn;
    int roundNum=13;
    char rollAgain='Y';
    char rollDieAgain='N';
    for (int i =0;i<roundNum;i++) {


        int hand[HAND_SIZE];
        rollDice(hand);
        while (rollAgain == 'Y' && count > 0) {

            cout << printHand(hand) << endl;
            cout << count << " Rolls remaining" << endl;
            cout << "Do you want to roll again? (Y or N)";
            cin >> rollAgain;
            count--;

            if (rollAgain == 'Y') {
                for (int i = 0; i < HAND_SIZE; i++) {
                    cout << "Do you want to keep die #" << i + 1 << "? (Y or N) ";
                    cin >> rollDieAgain;
                    hand[i] = saveNums(hand[i], rollDieAgain);
                }
            }
        }
        rollAgain='Y';
        count=3;
        cout << "Which category do you want to score this hand as?\n"
                "( 1) Ones\n"
                "( 2) Twos\n"
                "( 3) Threes\n"
                "( 4) Fours\n"
                "( 5) Fives\n"
                "( 6) Sixes\n"
                "( 7) Three of a Kind\n"
                "( 8) Four of a Kind\n"
                "( 9) Full House\n"
                "(10) Small Straight\n"
                "(11) Large Straight\n"
                "(12) Yahtzee!\n"
                "(13) Chance\n" << endl;
        cout << "Category #: ";
        cin >> userIn;
        die1 = hand[0];
        die2 = hand[1];
        die3 = hand[2];
        die4 = hand[3];
        die5 = hand[4];

        switch (userIn) {
            case 1:
                score += scoreOnes(die1, die2, die3, die4, die5);
                break;
            case 2:
                score += scoreTwos(die1, die2, die3, die4, die5);
                break;
            case 3:
                score += scoreThrees(die1, die2, die3, die4, die5);
                break;
            case 4:
                score += scoreFours(die1, die2, die3, die4, die5);
                break;
            case 5:
                score += scoreFives(die1, die2, die3, die4, die5);
                break;
            case 6:
                score += scoreSixes(die1, die2, die3, die4, die5);
                break;
            case 7:
                score += scoreThreeKind(die1, die2, die3, die4, die5);
                break;
            case 8:
                score += scoreFourKind(die1, die2, die3, die4, die5);
                break;
            case 9:
                score += scoreFullHouse(die1, die2, die3, die4, die5);
                break;
            case 10:
                score += scoreLargeStraight(die1, die2, die3, die4, die5);
                break;
            case 11:
                score += scoreSmallStraight(die1, die2, die3, die4, die5);
                break;
            case 13:
                score += Chance(die1, die2, die3, die4, die5);
                break;
            case 12:
                score += scoreYahtzee(die1, die2, die3, die4, die5);
                break;
        }

        cout <<"Your Current score is: " <<score<<endl;


    }

    return 0;
}
