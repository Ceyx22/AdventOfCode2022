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
    int priorities = 0;
    std::ifstream datafile;
    std::string currLine;
    datafile.open(R"(\Users\fm278\CLionProjects\AdventOfCode\dataDayThree.txt)");
    std::map <char , int> sameChar;

    while (getline (datafile, currLine)) {
        int mid = (currLine.length()/2);
        std::string compartmentOne = currLine.substr(0, mid);
        std::string compartmentTwo = currLine.substr(mid, currLine.length());
        char ch = FindCommonLet(compartmentOne, compartmentTwo);
        if (isupper(ch)){
            priorities += int(ch) - 38;
        }else {
            priorities += int(ch) - 96;
        }


    }
    printf("sum %i \n", priorities);
}
char FindCommonLet(std::string c1, std::string c2){
    for (auto &ch : c1) {
        if(c2.find(ch) != std::string::npos){
            return ch;
        }
    }
    return 0;
}
//std::map <char , int> listOfLettersInCommon(std::string l1, std::string l2){
//    std::map<char, int> common;
//    std::map<char, int> c1 = listOfLetters(l1);
//    std::map<char, int> c2 = listOfLetters(l2);
//    std::map<char, int>::iterator it;
//    for (auto it2 = c1.begin(); it2 != c1.end(); it2++) {
//        it = c2.find(it2->first);
//        if (it != c2.end()){
//            //found val
//            int z = LowerNum(it -> second, it2 -> second);
//            printf("Lowest Num: %i \n", z);
//            common[it2 -> first] = z;
//
//        }
//    }
//    print_map(common);
//    return common;
//}
//
//std::map <char , int> listOfLetters(std::string list){
//    std::map<char, int> let;
//    std::map<char, int> let2;
//    std::map<char, int>::iterator it;
//    for(char i : list){
//        it = let.find(i);
//        if (it != let.end()){
//            //found val
//            let.at(i) = let.at(i) + 1;
//        } else{
//            let[i] = 1;
//        }
//    }
//    for (auto it2 = let.begin(); it2 != let.end(); it2++) {
//        int i = it2 -> second;
//        if(i != 1){
//            let2[it2->first] = it2->second;
//        }
//    }
//    return let2;
//}
//
//template<typename K, typename V>
//void print_map(std::map<K, V> const &m){
//    for (auto const &pair: m) {
//        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
//    }
//}
//int calcPriority(std::map <char , int> sameChar){
//    int priority = 0;
//    for (auto it = sameChar.begin(); it != sameChar.end(); it++) {
//        int i = it -> second;
//        char c = it->first;
//        if(isupper(c)){
//            priority = priority + (c - 40)*i;
//        }else{
//            priority = priority + (c - 96)*i;
//        }
//    }
//
//
//    return priority;
//}
//std::vector<char> getAllKeys(std::map<char, int> map){
//    std::vector<char> keys;
//    for (auto it = map.begin(); it != map.end(); it++) {
//        keys.push_back(it->first);
//    }
//    return keys;
//}
//std::vector<int> getAllValues(std::map<char, int> map){
//    std::vector<int> value;
//    for (auto const& element : map) {
//        value.push_back(element.second);
//    }
//    return value;
//}
//
//bool numSameVal(std::vector<char> vect1, std::vector<char> vect2){
//    for(int i = 0; i < vect2.size(); i++){
//        if (std::find(vect1.begin(), vect1.end(), vect2.at(i)) != vect1.end()) {
//            return true;
//        }
//    }
//    return false;
//}
//int LowerNum(int val1, int val2){
//    printf("Val 1: %i Val2: %i \n", val1, val2);
//    if(val1 < val2){
//        return val1;
//    } else if (val1 > val2){
//        return val2;
//    } else if(val1 == val2){
//        return val2;
//    }else{
//        return 0;
//    }
//
//}
//void printVector(std::vector <char> const &a) {
//    std::cout << "The vector elements are : ";
//    for(char i : a)
//        std::cout << i << ' ';
//    printf("\n");
//}
//
//std::vector<char> stringToVector(std::string s){
//    std::vector<char> v;
//    std::copy(s.begin(), s.end(), std::back_inserter(v));
//    return v;
//}

