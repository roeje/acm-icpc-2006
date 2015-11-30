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
    for(int i = 0;i<io.length();++i){
        if(!(io[i]>='a' && io[i]<='z') && !(io[i]>='A' && io[i]<='Z')) io[i] = ' ';
        else if(io[i]>='A' && io[i]<='Z') io[i] = 'a'+io[i]-'A';
    }
    split_str(io);
}

void split_str(string &str){
    stringstream ss(str);

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
    istream& data = cin;
    read_data(data);
    for(int i = 0; i < results.size(); ++i){
        cout << setw(4) << results.at(i).second << " " << results.at(i).first << endl;
    }
    return 0;
}