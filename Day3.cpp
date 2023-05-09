//
// Created by fm278 on 5/4/2023.
//

#include "Day3.h"
#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include <map>
//#include <algorithm>
// Check if vector contains an element

void Day3(){

    std::ifstream datafile;
    std::string currLine;
    datafile.open(R"(\Users\fm278\CLionProjects\AdventOfCode\dataDayThree.txt)");
    std::map <char , int> sameChar;

    while (getline (datafile, currLine)) {
        std::map <char , int> charIn1;
        std::map <char , int> charIn2;

        int mid = (currLine.length()/2);
        std::string compartmentOne = currLine.substr(0, mid);
        std::string compartmentTwo = currLine.substr(mid, currLine.length());
//        printf("C1 length: %i \n", compartmentOne.length());
//        printf("C2 length: %i \n", compartmentTwo.length());
        std::vector<char> key1 = stringToVector(compartmentOne);
        std::vector<char> key2 = stringToVector(compartmentTwo);

        for(int i = 0; i < mid; i++){
            if(charIn1.find(compartmentOne[i]) != charIn1.end()) {
                //value is found
                charIn1.at(compartmentOne[i]) = charIn1.at(compartmentOne[i]) + 1;

            }else {
                //value not found
                charIn1.insert({compartmentOne[i], 1});
            }
            if(charIn2.find(compartmentTwo[i]) != charIn2.end()) {
                //value is found
                charIn2.at(compartmentTwo[i]) = charIn2.at(compartmentTwo[i]) + 1;

            }else {
                //value not found
                charIn2.insert({compartmentTwo[i], 1});
            }
        }

        if()
//        printf("Compartment 1: %s Compartment 2: %s \n", compartmentOne.c_str(), compartmentTwo.c_str());
//        std::cout << numSameVal(key1, key2) << std::endl;

    }
    //print_map(sameChar);
}

template<typename K, typename V>
void print_map(std::map<K, V> const &m){
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
int calcPriority(char x){
    int priority = 0;
    if(isupper(x)){
        priority = x - 40;
    }else{
        priority = x - 96;
    }
    return priority;
}
std::vector<char> getAllKeys(std::map<char, int> map){
    std::vector<char> keys;
    for (auto it = map.begin(); it != map.end(); it++) {
        keys.push_back(it->first);
    }
    return keys;
}
std::vector<int> getAllValues(std::map<char, int> map){
    std::vector<int> value;
    for (auto const& element : map) {
        value.push_back(element.second);
    }
    return value;
}

std::map<char, int> compareVect(std::vector<char> key1, std::vector<char> key2, std::vector<int> val1, std::vector<int> val2){
    std::map<char, int> sameChar;
    for (char i : key1){
        if (std::find(key2.begin(), key2.end(), i)) {
            //Element found
            int lowerNum = LowerNum(val1, val2, i);
            sameChar.insert({key1.at(i), calcPriority(key1.at(i)) * lowerNum});
        }
    }
    return sameChar;
}
bool numSameVal(std::vector<char> vect1, std::vector<char> vect2){
    for(int i = 0; i < vect2.size(); i++){
        if (std::find(vect1.begin(), vect1.end(), vect2.at(i)) != vect1.end()) {
            return true;
        }
    }
    return false;
}
int LowerNum(std::vector<int> vect1, std::vector<int> vect2, int pos){
    if(vect1.at(pos) < vect2.at(pos)){
        return vect1.at(pos);
    } else if(vect1.at(pos) > vect2.at(pos)){
        return vect2.at(pos);
    } else if(vect1.at(pos) == vect2.at(pos)){
        return vect2.at(pos);
    }else{
        return 0;
    }

}
void printVector(std::vector <char> const &a) {
    std::cout << "The vector elements are : ";
    for(char i : a)
        std::cout << i << ' ';
    printf("\n");
}

std::vector<char> stringToVector(std::string s){
    std::vector<char> v;
    std::copy(s.begin(), s.end(), std::back_inserter(v));
    return v;
}

