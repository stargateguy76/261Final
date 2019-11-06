/* CSCI 261 A5: PPM Image Editor
 *
 * Author: Allan Huntington
 *
 * this code inputs an image as a vector and the mofidies the pixel colors to change the image
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <vector>
#include <string>
#include <fstream>


// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

bool isLargeStraight( int die1, int die2, int die3, int die4, int die5 ) {
    int x[5];
    int tempVal;
    int score=0;
    bool isScore=false;
    bool zero;
    int count=0;
    x[0]=die1;
    x[1]=die2;
    x[2]=die3;
    x[3]=die4;
    x[4]=die5;
    for(int j =0;j<5;j++)
    {
        for(int i=0;i<4;i++)
        {
            if(x[i]>x[i+1])
            {
                tempVal=x[i];
                x[i]=x[i+1];
                x[i+1]=tempVal;
            }


        }
    }

    for(int i=0;i<=4;i++)
    {
        if(x[0]==1&&x[1]==2&&x[2]==3&&x[3]==4&&x[4]==5)
        {
            count++;
        }
        else if(x[0]==2&&x[1]==3&&x[2]==4&&x[3]==5&&x[4]==6)
        {
            count++;
        }


    }
    if(count==5)
    {
        isScore=true;;
    }


    return isScore;
}



int main ()
{
    return 0;
}
