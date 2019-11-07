#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include "ctime"
#include <vector> 
using namespace std;

class godzilla{
public:
    godzilla();
    void setHP(int health);
    void setPL(int powerLevel);
    void setName(string name1);
    void print();

private:
    string name;
    int healthPoints;
    int PL;

};
godzilla::godzilla()
{
    name="godzilla";
    healthPoints=rand() % 50+50;
    PL=rand() % 15+10;
}
void godzilla::setHP(int health) {
    if(health >0)
    {
        healthPoints=health;
    }

}
void godzilla::setPL(int powerLevel) {
    if(powerLevel>0)
    {
        PL=powerLevel;
    }

}
void godzilla::setName(string name1)  {
    name=name1;
}
void godzilla::print() {
    cout << "health: "<< healthPoints << " Power Level: "<<PL<< " Name: "<<name <<endl;
}
int main() {
    srand( time(0) );
    int health;
    int powerLevel;
    godzilla godzilla1;
    godzilla mechagodzilla;
    cout<< "Please enter the HP of Mehcagodzilla: ";
    cin>> health;
    cout <<endl;
    cout<< "Please enter the Power Level of Mehcagodzilla: ";
    cin>> powerLevel;
    cout <<endl;
    mechagodzilla.setHP(health);
    mechagodzilla.setPL(powerLevel);
    mechagodzilla.setName("mechagodzilla");99
    godzilla1.print();
    mechagodzilla.print();
}