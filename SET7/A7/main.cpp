// Allan Huntington 11/8//19
// this code reads the modified stars file and prints them using sfml and classes

#include <iostream>
#include <fstream>
#include <vector>
 #include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;// using the standard namespace
class star
{
public:

 void makeStars( vector<double> x, vector<double> y,vector <double> bright,RenderWindow &window); // create the function to draw stars

};
void star::makeStars( vector<double> x, vector<double> y, vector <double> bright,RenderWindow &window) // creates the draw stars function
{
    for(int i=0;i<bright.size();i++) { // loop for the total number of stars.

        int shadeOfGray = (int)( ( 255.0 * bright.at(i) ) /7.96 );
        sf::CircleShape star;
        star.setPosition(x.at(i), y.at(i));
        star.setRadius(2);

        star.setFillColor( Color(shadeOfGray, shadeOfGray, shadeOfGray) ); // set the color of the star based on the brightness
        window.draw(star);

    }
}


int main() {
   vector <double> xPos; //create a vector for the xPos yPos and brightness
   vector <double> yPos;
   vector <double> bright;
   double  temp1;
   double temp2;
   double temp3;
    ifstream starIn("modifiedStars.txt"); // read in the text file

    if(starIn.fail()) // if the chart does not open, show an error message
    {
        cout<<"failed to open file"<<endl;
        return -1;
    }

   while(!starIn.eof())
    {
        starIn>>temp1; // fill the array of values from the text file
        starIn>>temp2;
        starIn>>temp3;
        xPos.push_back(temp1);
        yPos.push_back(temp2);
        bright.push_back(temp3);

    }
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

   starIn.close();
   star stars; // create a star object.

    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
        // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************

        stars.makeStars(xPos,yPos,bright,window); // call the function to print all of the stars in the given window

        //****************************************
        //  ADD ALL OF OUR DRAWING ABOVE HERE
        //****************************************

        window.display();                       // display the window

        //****************************************
        // HANDLE EVENTS BELOW HERE
        //****************************************
        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if( event.type == Event::Closed ) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();                 // then close our window
            }
        }
    }
    return 0;

                        // report our program exited successfully
}