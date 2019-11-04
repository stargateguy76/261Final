/* CSCI 261 L2A
 * Math Equations
 *
 * Authors: Charles O'Brien and Allan Huntington
 *
 * This assignment prompts the user for values needed to solve the ideal gas law and Ohm's Law
 */

#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double P; // initialize all of the values needed in the equations
    double T;
    double vol;
    double long n;

    double I;
    double volt;
    int res;

    const double R = 8.314;
    cout << "Input Temperature, Volume, and number of moles" << endl; // prompt user for the needed input values

    cin >> T >> vol >> n;

    cout << "Input Voltage and Resistance" << endl;

    cin >> volt >> res;

    P = (n*R*T)/vol; // calculate the pressure and current values
    I = volt/res;

    cout << "THe pressure is: " << P << " Pascals." << endl; // print the results.
    cout << "The current is: " << I << " Amps." << endl;

    return 0;
}