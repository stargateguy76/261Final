
// Allan Huntington 11/8/19


#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "ctime"

using namespace std;

int gameScheduler (int d1,int d2,int d3,int N) // create function with 4 int inputs
{
    int dayCount=0; // start at day 1 with a count of 0 days so far
    int dayTally=1;
    while (dayCount<N) // when the campaign is complete, end the loop
    {

        if((dayTally%d1!=0) &&(dayTally%d2!=0) && (dayTally%d3!=0)) // if there are no confiicts continue adding days
        {
            dayCount++;

        }
        dayTally++;
    }
    return(dayTally-1); // return the number of days it took -1 for the first day
}

int main() {

   cout<< gameScheduler(5,7,9,1); // call the function with the times and days

}