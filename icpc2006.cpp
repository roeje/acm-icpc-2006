//
// Created by Jesse on 12/1/2015.
//

#include <iostream>
#include <sstream>
#include <map>
#include <regex>
#include <iomanip>
using namespace std;

void readData(istream& input);
void updateCount(string& input);
void filterText(string& input);

pair <string, int> countForWord;
vector <pair <string, int>> result;
map <string, int> freqMap;


void readData (istream &input) {
    string currentWord;

    /*Iterates through each word in the text input*/
    /*Calls filter method for each word in paragraph*/
    while (input >> ws >> currentWord) {
        if (currentWord != "#"){
            filterText(currentWord);
        }
        else {
            if (countForWord.first != "") {
                result.push_back(countForWord);
            }
            countForWord = make_pair("", 0);
            freqMap.clear();
        }
    }

    /*Output final frequency count after map has been built*/
    for(int it = 0; it < result.size(); ++it){
        cout << setw(4) << result.at(it).second << " " << result.at(it).first << endl;
    }
}

/*Handles the update of the frequency count for each unique word*/
void updateCount(string& input){
    stringstream data(input);

    while (data.good()) {
        string current = "";
        data >> current;
        if(current != ""){
            transform(current.begin(), current.end(), current.begin(), ::tolower);
            freqMap[current] += 1;
            if(freqMap[current] > countForWord.second){
                countForWord = make_pair(current, freqMap[current]);
            }
        }
    }
}

/*Checks each word for invalid characters and if found replaces with whitespace*/
void filterText(string& input){
    for(int it = 0; it < input.length(); ++it) {
        if(!(input[it] >= 'a' && input[it] <= 'z') && !(input[it] >= 'A' && input[it] <= 'Z')) {
            input[it] = ' ';
        }
        else if(input[it] >= 'A' && input[it] <= 'Z') {
            input[it] = 'a' + input[it] - 'A';
        }
    }
    updateCount(input);
}

/*Main that creates istream object passed to solving functions*/
int main() {

#ifndef ONLINE_JUDGE
    string testData = "This is a simple file of test data, which should"
            "not cause your program any trouble. Do note that"
            "it contains several punctuation characters. Of course,"
            "this is not really a problem, because such characters"
            " are treated in the same way as spaces."
            "#"
            "Don't use contractions; it isn't nice."
            "#"
            "aBc def AbC def dfe ABC"
            "#"
            "123"
            "#";

    istringstream data (testData);
#else
    istream& data = cin;
#endif
    readData(data);
}