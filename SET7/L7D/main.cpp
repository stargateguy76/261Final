#include <fstream>
#include <iostream>
#include <memory>
#include "ctime"

using namespace std;

class godzilla{  // create the godzilla class
public:
    godzilla();  // Create the public functions to be called later
    void setHP(double health);
    void setPL(double powerLevel);
    void setName(string name1);
    void print();

private: // set the private values of the class that cannot be directly modified.
    string name;
    double healthPoints;
    double PL;

};
godzilla::godzilla()  // create default constructor class
{
    name="godzilla";
    healthPoints=rand() % 50+50;
    PL=rand() % 15+10;
}
void godzilla::setHP(double health) { // set health function
    if(health >0) // if health is postive assign it otherwise generate a random value
    {
        healthPoints=health;
    } 
    else
    {
        healthPoints=rand() % 50+50;
    }

}
void godzilla::setPL(double powerLevel) { // set power level function
    if(powerLevel>0)  //if power level is positive assign it otherwise make a random value
    {
        PL=powerLevel;
    }
    else 
    {
        PL=rand() % 15+10;
    }

}
void godzilla::setName(string name1)  { // set name function

    name=name1; // set string to the name
}
void godzilla::print() {  // print the health power level and name
    cout << "health: "<< healthPoints << " Power Level: "<<PL<< " Name: "<<name <<endl;
}
int main() {
    srand( time(0) ); // create seed for random number generation
    double health;
    double powerLevel;

    godzilla godzilla1;  // create two godzilla objects.
    godzilla mechagodzilla;
    cout<< "Please enter the HP of godzilla: "; // have the user setup the godzilla
    cin>> health;
    cout <<endl;
    cout<< "Please enter the Power Level godzilla: ";
    cin>> powerLevel;
    cout <<endl;
    godzilla1.setHP(health);
    godzilla1.setPL(powerLevel);
    godzilla1.setName("mechagodzilla");
    godzilla1.print();  // print out the stats of both godzillas
    mechagodzilla.print();
    return 0;
}