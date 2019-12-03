#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
#include <stdlib.h>
#include <ctime>            // include all the library needed for this program.
using namespace std;

// create a 2d vector that stores the points for each word length, for example, 3 letters long is 2 points, etc
map<int, int> POINTS {{3, 1}, {5, 2}, {6, 3}, {7, 5}, {8, 11}};

/******************************************************************************/

class Dictionary { // create the dictionary class that will allow us to find and compare words
public:
    Dictionary();
    Dictionary(string, int word_length = 3); // define a varible that is a string of at least 3 letters long.
    ~Dictionary();

    unordered_set<string> words; // create unordered sets of strings, to allow us to have strings of any length, for user words, words and prefixes
    unordered_set<string> userWords;
    unordered_set<string> prefixes;
};

Dictionary::Dictionary() {};

// Load the word dictionary and prefixes dictionary from a given file, in this case the dictionary text file, seperate words from prefixes.
Dictionary::Dictionary(string path, int word_length) {
    string line;
    ifstream file(path);
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.length() >= word_length) {
                // Add to word dictionary
                this->words.insert(line);

                // Add to prefixes dictionary
                for (int i = 1; i < line.length(); i++) {
                    this->prefixes.insert(line.substr(0, i));
                }
            }
        }
    }
    file.close();
}

Dictionary::~Dictionary() {};

/******************************************************************************/

// Boggle board class this will allow us to make the board, print the board and score the board.
class Boggle {
private:
    struct square { // create a struct that will store the board as a square, depending on the size of the grid desired
        string value;
        int row;
        int col;
        vector<int> neighbors;
        vector<string> list;

        square(int row, int col);
    };

    const int size; // make the size of the board constant
    shared_ptr<const Dictionary> dict;
    map<int, int> points; // include the points, the board square, and the unordered sets
    vector<square> board;
    unordered_set<string> found_words;
    unordered_set<string> user_found_words;

    void Words(int position); // setup the words and user words functions that will allow the computer to find all of the words as well as the user words
    void Words(int position, string, vector<bool> &visited);
    void userWords(string string);


public:
    Boggle(shared_ptr<const Dictionary> dict, int size = 4, map<int, int> points = POINTS); // create the default class
    ~Boggle();

    void Load(string letters);
    void Print();
    void Score();
    void userIn();
};

// Boggle board constructor that creates the boggle board
Boggle::Boggle(shared_ptr<const Dictionary> dict, int size, map<int, int> points):
        dict(dict), size(size), points(points) {
    int row, col;

    // Add squares to the board based the on the size of the board, filling it with squares
    for (int i = 0; i < size * size; i++) {
        row = i / size;
        col = i % size;
        board.push_back(square(row, col));
    }

    // Add each square's neighbors, following a template for creating squares.
    vector<int> shift {-1, 0, 1}; // create a square board based on the max size square, and then any remainders. IE a 5*5, 4*4, etc
    for (square &sq : board) {
        for (int row_shift : shift) {
            for (int col_shift : shift) {
                row = sq.row + row_shift;
                col = sq.col + col_shift;
                if (row >= 0 && row < size && col >= 0 && col < size && !(row_shift == 0 && col_shift == 0)) {
                    sq.neighbors.push_back(row * size + col); // fill the board with the squares that make the most square board
                }
            }
        }
    }
}

Boggle::~Boggle() {}

// Boggle square constructor creates the row and col sized board
Boggle::square::square(int row, int col) {
    this->row = row;
    this->col = col;
}

// Load a string of letters into the board that fill all of the squares
void Boggle::Load(string letters) {
    int i = 0;
    for (square &it : board) {
        it.value = letters[i];
        i += 1;
    }
    // Clear any previously found words
    found_words.clear();
}

// Print the board
void Boggle::Print() {

    cout<< "Welcome to Boggle, here is your randomly generated board!" << endl;
    for (const square &sq : board) {
        cout << sq.value << " ";
        if (sq.col == size - 1) {
            cout << endl;
        }
    }
}
// User input constructor, allows the user to enter the words they can find in the board, then prints the comptuers words
void Boggle::userIn()
{

    string userInput;
    cout <<"Enter your words, and then enter done! when finished" <<endl;
    while(userInput != "done!")
    {
        cin>>userInput;
        userWords(userInput);

    }
    cout << "The computer found these words:"<<endl;
}

// Find all words, then calculate the score
void Boggle::Score() {
    int score = 0;
    int userScore=0;
    bool ComputerScore=true;

    // Find words for all squares on the board
    for (int i = 0; i < board.size(); i++) {
        Words(i);
    }

    // For each word, look up points and add to the score
    map<int, int>::iterator point;
    if(ComputerScore == true)
    {
        for (const string &word : found_words) {
            // Find the smallest point map key greater than word length, then move back one step
            // to get the largest key less than or equal to word length, e.g. 4->5->3
            point = points.upper_bound(word.length());
            --point;
            score += point->second;
            cout<<word<<endl;
        }
        cout << "The computers Score was: ";
        cout << score <<endl;
        for (const string &userWords : user_found_words) {
            // Find the smallest point map key greater than word length, then move back one step
            // to get the largest key less than or equal to word length, e.g. 4->5->3
            point = points.upper_bound(userWords.size());
            --point;
            userScore += point->second;
            //cout << userWords <<"*"<<endl;
        }
        cout << "Your score was: ";
        cout<<userScore<<endl;
    }


}

void Boggle::userWords(string input)
{
    if ((dict->words.find(input) != dict->words.end()))  { // if the user words are a word according to the dictonary, add them to the user found words
        user_found_words.insert(input);
    }
}
// Top-level Words function overload; sets up visited vector that prevents the computer from creating the same word twice
void Boggle::Words(int position) {
    vector<bool> visited (size*size, false);
    Words(position, "", visited);
}



// Find all words starting at a given position
void Boggle::Words(int position, string string, vector<bool> &visited) {

    square &sq = board[position];
    string = string + sq.value;
    visited[position] = true;

    // If the string is a word, add it to the found words
    if (dict->words.find(string) != dict->words.end()) {
        found_words.insert(string);
    }

    // If the string is a prefix, continue looking
    if (dict->prefixes.find(string) != dict->prefixes.end()) {
        for (const int &neighbor : sq.neighbors) {
            if (!visited[neighbor]) {
                Words(neighbor, string, visited);
            }
        }
    }

    visited[position] = false;
}
// Random letter generator, uses a lookup table, and generates a random string of letters, of length N, based on the lookup table
string gen_random(char *s, const int len) {
    static const char alphanum[] =

            "abcdefghijklmopqrstuvwxyz";

    for (int i = 0; i < len; ++i) { // generate an array of charecters of length len
        s[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    string boardString="";

    int i;
    for (i = 0; i < len; i++) { // turn the array into a string by adding the letters
        boardString = boardString + s[i];
    }

    s[len] = 0;
    return(boardString); // return the string
}

/******************************************************************************/
// runs the boggle functions defined in the class
int main() {
    srand(time(NULL)); // use srand to insure we get different letters each time
    auto dict = make_shared<const Dictionary>("twl06.txt"); // input the dictionary text file into the dictonary class
    char boardLetters[16];
    char playAgain='y';// define the board letters string

while(playAgain=='y') // loop the game so the user can play as many games as they want.
{
    Boggle b(dict);
    b.Load(gen_random(boardLetters,16)); // create the string based on the starting string and length

    b.Print(); // print the board
    b.userIn(); // ask the user for their words
    b.Score(); // score the board based on the computers findings and the user words
    cout << "would you like to play again? (y/n): ";
    cin >> playAgain;

}
cout<<"thanks for playing!"<<endl;

    return (0);
}