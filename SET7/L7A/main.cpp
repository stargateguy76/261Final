#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

int main() {
    // display "Hello, World!" -- this still appears in our Run terminal as before
    cout << "Hello, World!" << endl;

    // create a RenderWindow object
    // specify the size to be 640x640
    // set the title to be "SFML Example Window"
    RenderWindow window( VideoMode(640, 640), "SFML Example Window" );

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING BELOW HERE
    //********************************************

    //********************************************
    //  PLACE ANY FILE INPUT PROCESSING ABOVE HERE
    //********************************************

    // while our window is open, keep it open
    // this is our draw loop
    while( window.isOpen() ) {
        window.clear( Color::Black );           // clear the contents of the old frame
                                                // by setting the window to black

        //****************************************
        //  ADD ALL OF OUR DRAWING BELOW HERE
        //****************************************


        CircleShape star;
        star.setPosition( 115, 40 );
        star.setRadius(40 );
        star.setFillColor( Color::Green );
        window.draw( star);

        CircleShape star2;
        star2.setPosition( 115, 80);
        star2.setRadius(40 );
        star2.setFillColor( Color::Green );
        window.draw( star2);

        CircleShape star3;
        star3.setPosition( 115, 120);
        star3.setRadius(40 );
        star3.setFillColor( Color::Green );
        window.draw( star3);

        CircleShape star4;
        star4.setPosition( 115, 160);
        star4.setRadius(40 );
        star4.setFillColor( Color::Green );
        window.draw( star4);

        CircleShape star5;
        star5.setPosition( 115, 200);
        star5.setRadius(40 );
        star5.setFillColor( Color::Green );
        window.draw( star5);

        CircleShape star6;
        star6.setPosition( 135, 240);
        star6.setRadius(5 );
        star6.setFillColor( Color::Black );
        window.draw(star6);

        CircleShape star7;
        star7.setPosition( 150, 240);
        star7.setRadius(5 );
        star7.setFillColor( Color::Black );
        window.draw(star7);

        RectangleShape rect;
        rect.setSize( Vector2f( 50, 5 ) );
        rect.setPosition( 80, 70 );
        rect.setFillColor( Color(0, 0, 255));
        window.draw( rect );

        RectangleShape rect2;
        rect2.setSize( Vector2f( 50, 5 ) );
        rect2.setPosition( 180, 70 );
        rect2.setFillColor( Color(0, 0, 255));
        window.draw( rect2 );

        RectangleShape rect3;
        rect3.setSize( Vector2f( 50, 5 ) );
        rect3.setPosition( 80, 110 );
        rect3.setFillColor( Color(0, 0, 255));
        window.draw( rect3 );

        RectangleShape rect4;
        rect4.setSize( Vector2f( 50, 5 ) );
        rect4.setPosition( 180, 110 );
        rect4.setFillColor( Color(0, 0, 255));
        window.draw( rect4 );

        RectangleShape rect5;
        rect5.setSize( Vector2f( 50, 5 ) );
        rect5.setPosition( 80, 150 );
        rect5.setFillColor( Color(0, 0, 255));
        window.draw( rect5 );

        RectangleShape rect6;
        rect6.setSize( Vector2f( 50, 5 ) );
        rect6.setPosition( 180, 150 );
        rect6.setFillColor( Color(0, 0, 255));
        window.draw( rect6 );

        RectangleShape rect7;
        rect7.setSize( Vector2f( 50, 5 ) );
        rect7.setPosition( 80, 190 );
        rect7.setFillColor( Color(0, 0, 255));
        window.draw( rect7 );

        RectangleShape rect8;
        rect8.setSize( Vector2f( 50, 5 ) );
        rect8.setPosition( 180, 190 );
        rect8.setFillColor( Color(0, 0, 255));
        window.draw( rect8 );



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

    return EXIT_SUCCESS;                        // report our program exited successfully
}