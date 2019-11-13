#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// Map word lengths to points
map<int, int> POINTS {{3, 1}, {5, 2}, {6, 3}, {7, 5}, {8, 11}};

/******************************************************************************/

class Dictionary {
public:
    Dictionary();
    Dictionary(string, int word_length = 3);
    ~Dictionary();

    unordered_set<string> words;
    unordered_set<string> userWords;

    unordered_set<string> prefixes;
};

Dictionary::Dictionary() {};

// Load the word dictionary and prefixes dictionary from a given file
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

// Boggle board class
class Boggle {
private:
    struct square {
        string value;
        int row;
        int col;
        vector<int> neighbors;
        vector<string> list;

        square(int row, int col);
    };

    const int size;
    shared_ptr<const Dictionary> dict;
    map<int, int> points;
    vector<square> board;
    unordered_set<string> found_words;
    unordered_set<string> user_found_words;
    void Words(int position);
    void Words(int position, string, vector<bool> &visited);
    void userWords(string string);


public:
    Boggle(shared_ptr<const Dictionary> dict, int size = 4, map<int, int> points = POINTS);
    ~Boggle();

    void Load(string letters);
    void Print();
    void Score();
};

// Boggle board constructor
Boggle::Boggle(shared_ptr<const Dictionary> dict, int size, map<int, int> points):
        dict(dict), size(size), points(points) {
    int row, col;

    // Add squares to the board
    for (int i = 0; i < size * size; i++) {
        row = i / size;
        col = i % size;
        board.push_back(square(row, col));
    }

    // Add each square's neighbors
    vector<int> shift {-1, 0, 1};
    for (square &sq : board) {
        for (int row_shift : shift) {
            for (int col_shift : shift) {
                row = sq.row + row_shift;
                col = sq.col + col_shift;
                if (row >= 0 && row < size && col >= 0 && col < size && !(row_shift == 0 && col_shift == 0)) {
                    sq.neighbors.push_back(row * size + col);
                }
            }
        }
    }
}

Boggle::~Boggle() {}

// Boggle square constructor
Boggle::square::square(int row, int col) {
    this->row = row;
    this->col = col;
}

// Load a string of letters into the board
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
    for (const square &sq : board) {
        cout << sq.value << " ";
        if (sq.col == size - 1) {
            cout << endl;
        }
    }
}

// Find all words, then calculate the score
void Boggle::Score() {
    int score = 0;
    int userScore=0;
    bool ComputerScore=true;
    string userInput;

    while(userInput != "done!")
    {
        cout <<"Enter your words, and then enter done! when finished" <<endl;
        cin>>userInput;
        userWords(userInput);

    }


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
        cout << score <<endl;
        for (const string &userWords : user_found_words) {
            // Find the smallest point map key greater than word length, then move back one step
            // to get the largest key less than or equal to word length, e.g. 4->5->3
            point = points.upper_bound(userWords.size());
            --point;
            userScore += point->second;
            cout << userWords <<"*"<<endl;
        }
        cout<<userScore<<endl;
    }


}

void Boggle::userWords(string input)
{
    if (dict->words.find(input) != dict->words.end()) {
        user_found_words.insert(input);
    }
}
// Top-level Words function overload; sets up visited vector, whose size is determined at runtime
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

/******************************************************************************/

int main() {
    auto dict = make_shared<const Dictionary>("twl06.txt");
    Boggle b(dict);
    b.Load("abdgthrnsjrke");
    b.Print();
    b.Score();
}