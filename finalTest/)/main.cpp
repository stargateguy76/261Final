
// Allan Huntington 11/8/19


#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include "ctime"

using namespace std;


int main() {


double w,l,d,v,h; // create doubles for the values
cin >> w>>l>>d>>v>>h;
vector <double> slices; // create a vector for the slices

    slices.push_back(d*(l-h)*(w-v)); // fill the vector with all the possible slices
    slices.push_back(d*(h)*(w-v));
    slices.push_back(d*(l-h)*(v));
    slices.push_back(d*(h)*(v));

    cout<<fixed <<setprecision(3)<<*max_element(slices.begin(), slices.end()); // print the max value from the vector formatted properly


    return 0;
}