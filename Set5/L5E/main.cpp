/* CSCI261 Lab5D: Vectors
 *
 * Author: Allan Huntington
 *
 * have people enter a seriers of numbers and ouput info about those numbers.
 *
 *

 *
*/

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main() {
    int userIn;
    int totalNum=1;
    int tempVal;
    int min;
    int max;
    vector<int> Nums;
    cout<<"Your Number is";
    cin>>userIn;
    while(userIn>=0){ //while the user is inputing positive numbers, keep asking for numbers
        cin>>userIn;
        if(userIn>=0){
            Nums.push_back(userIn);
        }
        cout<<"Your Number is";



    }
    cout<<"So Awesome! you entered " << Nums.size() <<" numbers";
    min=Nums.at(0);
    for(int i=0;i<Nums.size();i++) // set the min, and if a smaller value is found, replace the min value with that value
    {
        if(min>Nums.at(i))
        {
            min=Nums.at(i);
        }
    }
    max=Nums.at(0);
    for(int i=0;i<Nums.size();i++) // set the max value and if a larger value is found replace the max value
    {
        if(max<Nums.at(i))
        {
            max=Nums.at(i);
        }
    }
    cout<<"The Numbers are"; // output the numbers
    for(int i=0;i<Nums.size();i++)
    {
        cout<<Nums.at(i);
    }
    cout<<endl;
    cout<<"The smallest number is: "<<min<<endl; // output the min and max numbers.
    cout<<"The largest number is: "<<max<<endl;

    return 0;
}