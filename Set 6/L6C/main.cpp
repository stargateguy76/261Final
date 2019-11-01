#include <iostream>

using namespace std;

int addFive( int x ) {
    x =x+5;
    return x;
}

// input: none
// output: a random number
// ERROR FOUND: Srand was used in the loop, this would create the same seed and prevent it from generating random numbers
// SOULTION: Move the srand function to main
int generateRandomNumber() {

    return rand() % 100;
}

void printSmileyFace()
{
    cout << "                  __ooooooooo__\n"
            "              oOOOOOOOOOOOOOOOOOOOOOo\n"
            "          oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
            "       oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
            "     oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
            "   oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
            "  oOOOOOOOOOOO*  *OOOOOOOOOOOOOO*  *OOOOOOOOOOOOo\n"
            " oOOOOOOOOOOO      OOOOOOOOOOOO      OOOOOOOOOOOOo\n"
            " oOOOOOOOOOOOOo  oOOOOOOOOOOOOOOo  oOOOOOOOOOOOOOo\n"
            "oOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo\n"
            "oOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOo\n"
            "oOOOOOO OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO OOOOOOo\n"
            " *OOOOO  OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  OOOOO*\n"
            " *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*\n"
            "  *OOOOOO  *OOOOOOOOOOOOOOOOOOOOOOOOOOO*  OOOOOO*\n"
            "   *OOOOOOo  *OOOOOOOOOOOOOOOOOOOOOOO*  oOOOOOO*\n"
            "     *OOOOOOOo  *OOOOOOOOOOOOOOOOO*  oOOOOOOO*\n"
            "       *OOOOOOOOo  *OOOOOOOOOOO*  oOOOOOOOO*      \n"
            "          *OOOOOOOOo           oOOOOOOOO*      \n"
            "              *OOOOOOOOOOOOOOOOOOOOO*          \n"
            "                   \"\"ooooooooo\"\"" << endl;
}

// input: three integers
// output: the sum of all three parameters
// ERROR FOUND: this code was adding x three times, instead of x,y,z
// SOLUTION: add all three varibles

int sum( int x, int y, int z ) {
    return x + y + z;
}


// ERROR FOUND: this code was not doing anything
// Solution Now this command multiplies the doubles together.
double multiply( double a, double b )
{
    return a*b;
}

int main() {
    srand( time(0) );

// SECTION I: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = changed the function to return a value, and assigned that value to numTrees
// TESTS: num trees =10 goes to 15, num trees 5 goes to 10

    cout << endl;
    cout << "******************" << endl;
    cout << "Section I" << endl;
    cout << "******************" << endl;

    int numTrees;
    cout << "How many trees do you currently have? ";
    cin >> numTrees;
    cout << "There are initially " << numTrees << " trees." << endl;
    numTrees=addFive(numTrees);
    cout << "We planted five trees, there are now " << numTrees << " trees." << endl;

    // SECTION II: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = created function that prints a smiley face called printSmileyFace()
// TESTS: run the function and look for smiley output.

    cout << endl;
    cout << "******************" << endl;
    cout << "Section II" << endl;
    cout << "******************" << endl;

    printSmileyFace();

    // SECTION III: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = moved the srand outside of the function to prevent the same seed.
// TESTS: 5 random numbers are generated each time it runs

    cout << endl;
    cout << "******************" << endl;
    cout << "Section III" << endl;
    cout << "******************" << endl;

    cout << "Five different random numbers are: " << endl;
    for( int i = 0; i < 5; i++ ) {
        cout << "\t" << generateRandomNumber() << endl;
    }

    // SECTION IV: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = changed the function to add all three numbers, and fixed the call to include num1,num2,num3.
// TESTS: 1,2,3 returns 6, 5,6,7 returns 18

    cout << endl;
    cout << "******************" << endl;
    cout << "Section IV" << endl;
    cout << "******************" << endl;

    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    cout << "The sum of all three is " << sum( num1, num2,num3 ) << endl;

    // SECTION V: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = added the parenthesis to the random function to allow it to call correctly
// TESTS: generates a random number, run 3 times

    cout << endl;
    cout << "******************" << endl;
    cout << "Section V" << endl;
    cout << "******************" << endl;

    cout << "Another random number is " << generateRandomNumber() << endl;

    // SECTION VI: update comment below on how you fixed this section's code, and tests run
// that show function is working properly
// FIX = added the function definition for the multiply function, and returns the product of the two
// TESTS: 2.2*2.2=4.84 2.3*4.5=10.35

    cout << endl;
    cout << "******************" << endl;
    cout << "Section VI" << endl;
    cout << "******************" << endl;

    double doub1, doub2;
    cout << "Enter two doubles: ";
    cin >> doub1 >> doub2;
    cout << "Their product is: " << multiply( doub1, doub2 ) << endl;

    cout << endl;
    cout << "******************" << endl;
    cout << "Section Done" << endl;
    cout << "******************" << endl;

    cout << endl << "Congrats!  You fixed them all (hopefully correctly!)" << endl << endl << "Goodbye" << endl << endl;

    return 0;
}