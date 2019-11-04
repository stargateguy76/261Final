/* CSCI261 Lab5D: Vectors
 *
 * Author: Allan Huntington
 *
 * This program builds a struct for a book, and then makes a series of books
 * asks the user to input the books then return selected information
 *
 *

 *
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;


int main() {

    struct book{        // create the struct for books
        string Author;
        string Title;
        double cost;
        int year;
    };
    int bookNum;

    book Books[5]; // decide how many books for the struct

    for(int i=0;i<5;i++) // fill the books with info
    {
        cout<<"Enter the author for book " << i+1<<endl;
        cin>> Books[i].Author;
        cout<<"Enter the title for book " << i+1<<endl;
        cin>> Books[i].Title;
        cout<<"Enter the cost for book " << i+1<<endl;
        cin>> Books[i].cost;
        cout<<"Enter the year for book " << i+1<<endl;
        cin>> Books[i].year;
    }
    cout<<"which Book would you like to view?"<<endl; // output the book number they are looking for.
    cin>>bookNum;
    bookNum=bookNum-1;
    cout<<"Author: ";
    cout<<Books[bookNum].Author<<endl;
    cout<<"Title: ";
    cout<<Books[bookNum].Title<<endl;
    cout<<"Cost: ";
    cout<<Books[bookNum].cost<<endl;
    cout<<"Year: ";
    cout<<Books[bookNum].year<<endl;

    return 0;
}

