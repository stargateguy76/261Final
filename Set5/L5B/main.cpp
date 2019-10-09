/* CSCI 261 Lab 5B
 *
 * Author: Allan Huntington
 * this program asks the user for an input on a n n*m matrix then outputs the matrix and the inverse of the matrix
 *
 */

// The include section adds extra definitions from the C++ standard library.

#include <iostream>
#include <cmath>// For cin, cout, etc.
#include <stdlib.h>
#include <time.h>




#include <string>
#include <fstream>
#include <iomanip>
#include <cmath> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.

using namespace std;
int main (){

    const int N=4;
    const int M=4;
     int array[N][M];
    int rowNum=0;
    int rowNum2=0;
    for(int i=0;i< N;i++)
    {
        rowNum=i;
        for(int i=0;i<M;i++)
        {
            cout<< "Enter Row " << rowNum+1 <<" column " <<i+1 <<":"<<endl;
            cin>>array[rowNum][i];
        }

    }
    cout<<"the array you entered was:"<<endl;
    for(int i=0;i< N;i++)
    {
        cout<<"[ ";

        rowNum2=i;
        for(int i=0;i<M;i++)
        {
            cout<<array[rowNum2][i]<<" ";
        }
        cout<<"]"<<endl;
    }
    cout<<"the transpose of the array is"<<endl;
    for(int i=0;i< N;i++)
    {
        cout<<"[ ";

        rowNum2=i;
        for(int i=0;i<M;i++)
        {
            cout<<array[i][rowNum2]<<" ";
        }
        cout<<"]"<<endl;
    }
cout<<"Have a nice day"<<endl;
    return 0; // signals the operating system that our program ended OK.
}
