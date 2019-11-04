/* CSCI 261 A5: Yahtzee
 *
 * Author: Allan Huntington
 *
 * this code useses yahtzee and dice functions to run a complete game of yatzee, keeping score and adding rounds.
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
#include "Dice.h"


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
    int count1=0,count2=0,count3=0,count4=0,count5=0,count6=0,count7=0,count8=0,count9=0,count10=0,count11=0,count12=0,count13=0;
    int roundNum=13;
    char rollAgain='Y';
    bool runAgain=true;
    char rollDieAgain='N';
    int hand[HAND_SIZE];
    for (int i =0;i<roundNum;i++) {


        if(runAgain==true)
        {
            rollDice(hand);
        }
        else
        {
        }

        while (rollAgain == 'Y' && count > 0 && runAgain==true) {

            printHand(hand);
            cout << count << " Rolls remaining" << endl;
            cout << "Do you want to roll again? (Y or N)";
            cin >> rollAgain;
            count--;

            if (rollAgain == 'Y') {
                for (int i = 0; i < HAND_SIZE; i++) {
                    cout << "Do you want to keep die #" << i + 1 << "? (Y or N) ";
                    cin >> rollDieAgain;
                    if(rollDieAgain=='N')
                    {
                        hand[i] = rollDie();
                    }

                }
            }
            else
            {

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
        runAgain=false;
        die1 = hand[0];
        die2 = hand[1];
        die3 = hand[2];
        die4 = hand[3];
        die5 = hand[4];

        switch (userIn) {
            case 1:
                if (count1 < 2 && scoreOnes(die1,die2,die3,die4,die5)>0) {
                    score += scoreOnes(die1, die2, die3, die4, die5);
                    count1++;
                    runAgain=true;
                }


                break;
            case 2:
                if (count2 < 2 && scoreTwos(die1,die2,die3,die4,die5)>0) {
                    score += scoreTwos(die1, die2, die3, die4, die5);
                    count2++;
                    runAgain=true;
                }

                break;
            case 3:
                if (count3 < 2 && scoreThrees(die1,die2,die3,die4,die5)>0) {
                score += scoreThrees(die1, die2, die3, die4, die5);
                count3++;
                    runAgain=true;
        }

                break;
            case 4:
                if(count4<2 && scoreFours(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreFours(die1, die2, die3, die4, die5);
                    count4++;
                    runAgain=true;
                }

                break;
            case 5:
                if(count5<2 && scoreFives(die1,die2,die3,die4,die5)>0) {
                    score += scoreFives(die1, die2, die3, die4, die5);
                    count5++;
                    runAgain=true;
                }

                break;
            case 6:
                if(count6<2 && scoreSixes(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreSixes(die1, die2, die3, die4, die5);
                    count6++;
                    runAgain=true;
                }

                break;
            case 7:
                if(count7<2 && scoreThreeKind(die1,die2,die3,die4,die5)>0){
                    score += scoreThreeKind(die1, die2, die3, die4, die5);
                    count7++;
                    runAgain=true;
                }

                break;
            case 8:
                if(count8<2 && scoreFourKind(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreFourKind(die1, die2, die3, die4, die5);
                    count8++;
                    runAgain=true;
                }

                break;
            case 9:
                if(count9<2 && scoreFullHouse(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreFullHouse(die1, die2, die3, die4, die5);
                    count9++;
                    runAgain=true;
                }


                break;
            case 10:
                if(count10<2 && scoreLargeStraight(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreLargeStraight(die1, die2, die3, die4, die5);
                    count10++;
                    runAgain=true;
                }

                break;
            case 11:
                if(count11<2 && scoreSmallStraight(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreSmallStraight(die1, die2, die3, die4, die5);
                    count11++;
                    runAgain=true;
                }

                break;
            case 13:
                if(count13<2 && Chance(die1,die2,die3,die4,die5)>0)
                {
                    score += Chance(die1, die2, die3, die4, die5);
                    count13++;
                    runAgain=true;
                }

                break;
            case 12:
                if(count12<2 && scoreYahtzee(die1,die2,die3,die4,die5)>0)
                {
                    score += scoreYahtzee(die1, die2, die3, die4, die5);
                    count12++;
                    runAgain=true;
                }

                break;
        }

        cout <<"Your Current score is: " <<score<<endl;


    }
    cout<<"Game over, your score was: "<<score<<endl;

    return 0;
}
