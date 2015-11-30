//
// Created by Jesse on 11/22/2015.
//

#include <iostream>
#include <sstream>
#include <map>
#include <regex>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

void read_data(istream &input);
void replace(string &io);
void split_str(string &str);

map <string, int> my_map;

pair <string, int> current_max;

vector <pair <string, int>> results;

string test_data = "This is a simple file of test data, which should\n not cause your program any trouble. Do note that\n it contains several punctuation characters. Of course, \n this is not really a problem, because such characters\n are treated in the same way as spaces.\n # \n Don't use contractions; it isn't nice.\n # \n# \n aBc def AbC def dfe ABC\n #123 \n#";

void read_data(istream &input){
    string word;

    while(input >> ws >> word){
        if(word != "#"){
            replace(word);
        }else{
            if(current_max.first != ""){
                results.push_back(current_max);
            }
            current_max = make_pair("", 0);
            my_map.clear();
        }
    }
}

void replace(string &io){
    for(int i = 0; i<io.size(); i++){
        switch (io.at(i)){
            case '.':
                io[i] = ' ';
                break;
            case '\'':
                io[i] = ' ';
                break;
            case ':':
                io[i] = ' ';
                break;
            case ';':
                io[i] = ' ';
                break;
            case ',':
                io[i] = ' ';
                break;
        }
    }
    split_str(io);
}

void get_biggest(map<string, int> &map) {
    pair<string, int> res;
}

void split_str(string &str){
    stringstream ss(str);
    //cout << "the stream: "<< ss<<end;
    while(ss.good()){
        string res = "";
        ss >> res;
        if(res != ""){
            std::transform(res.begin(), res.end(), res.begin(), ::tolower);
            my_map[res] += 1;
            if(my_map[res] > current_max.second){
                current_max = make_pair(res, my_map[res]);
            }
        }
    }

}

int main(){
    istringstream ss(test_data);
    read_data(ss);
    for(int i = 0; i < results.size(); ++i){
        cout << setw(4)<<results.at(i).second <<" "<<results.at(i).first<<endl;
    }
    return 0;
}