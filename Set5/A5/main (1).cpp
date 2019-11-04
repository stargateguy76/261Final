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

// Define any constants or global variables below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
    //declares the variables
    int numColumn;
    int numRow;
    int maxColor;
    int i;
    int j;
    int redNum;
    int greenNum;
    int blueNum;
    int grayVal;
    string temp;
    string fileName;
    string grayscaleName;
    string invertName;

    //declares the structure pixel
    struct Pixel{
        int red;
        int green;
        int blue;
    };

    //ask the user for the file name and checks for errors
    cout << "What file(s) do you wish to open?" << endl;
    cin >> fileName;
   
    
    ifstream picture(fileName);
    
    if(picture.fail()){
        cerr << "Error opening input file";
        return -1;
    }
    
    picture >> temp;
    picture >> numColumn;
    picture >> numRow;
    picture >> maxColor;

    //declares the vector for the 2D image
    vector< vector< Pixel > > image(numRow);

    //assigns values of the pixels
    for(i = 0; i < numRow; i++){
        vector<Pixel> temp(numColumn);
        for(j = 0; j < numColumn; j++){
        picture >> redNum;
        temp.at(j).red = redNum;
        picture >> greenNum;
        temp.at(j).green = greenNum;
        picture >> blueNum;
        temp.at(j).blue = blueNum;
        }
        image.at(i) = temp;
    }


    //grayscale conversion
    //creates the grayscale file
    fileName.erase(fileName.find(".ppm"), 4);
    grayscaleName = fileName + "_grayscale.ppm"; // creates .ppm file
    ofstream fileOutGray(grayscaleName);
    if (fileOutGray.fail()){
        cerr << "Error opening file to write" << endl;
        return -1;
    }

    //declares the grayscale vector and makes the values follwing the assigment template
   vector< vector< Pixel > > grayImage(numRow);
    for(i = 0; i < numRow; i++){
        vector<Pixel> temp(numColumn);
        for(j = 0; j < numColumn; j++){
            grayVal = image[i][j].red * 0.2989 + image[i][j].green * 0.5870 + image[i][j].blue * 0.1140;
            temp.at(j).red = grayVal;
            temp.at(j).green = grayVal;
            temp.at(j).blue = grayVal;
        }
       grayImage.at(i) = temp;
    }

    //outputs the . PPM file
    fileOutGray << temp << endl;
    fileOutGray << numColumn << " " << numRow << endl;
    fileOutGray << maxColor << endl;
    for(i = 0; i < numRow; i++){
        for(j = 0; j < numColumn; j++){
            fileOutGray << grayImage[i][j].red << endl;
            fileOutGray << grayImage[i][j].green << endl;
            fileOutGray << grayImage[i][j].blue << endl;
        }
    }

    //Inverted conversion
    //creates the Inverted file
    invertName = fileName + "_Inverted.ppm";
    ofstream fileOutInvert(invertName);
    //checks
    if (fileOutInvert.fail()){
        cerr << "Error opening file to write" << endl;
        return -1;
    }

    //declares the Inverted vector and fills the vector
    vector< vector< Pixel > > invertImage(numRow);
    for(i = 0; i < numRow; i++){
        vector<Pixel> temp(numColumn);
        for(j = 0; j < numColumn; j++){
            temp.at(j).red = maxColor - image[i][j].red;
            temp.at(j).green = maxColor - image[i][j].green;
            temp.at(j).blue = maxColor - image[i][j].blue;
        }
        invertImage.at(i) = temp;
    }

    //outputs the file
    fileOutInvert << temp << endl;
    fileOutInvert << numColumn << " " << numRow << endl;
    fileOutInvert << maxColor << endl;
    for(i = 0; i < numRow; i++){
        for(j = 0; j < numColumn; j++){
            fileOutInvert << invertImage[i][j].red << endl;
            fileOutInvert << invertImage[i][j].green << endl;
            fileOutInvert << invertImage[i][j].blue << endl;
        }
    }



    return 0; // signals the operating system that our program ended OK.
}