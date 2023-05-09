//
// Created by fm278 on 5/4/2023.
//

#ifndef ADVENTOFCODE_DAY3_H
#define ADVENTOFCODE_DAY3_H
#include <iostream>
#include <tuple>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

void Day3();
template<typename K, typename V>
void print_map(std::map<K, V> const &m);

int calcPriority(char x);
std::vector<char> getAllKeys(std::map<char, int> map);
std::vector<int> getAllValues(std::map<char, int> map);
std::map<char, int> compareVect(std::vector<char> key1, std::vector<char> key2, std::vector<int> val1, std::vector<int> val2);
bool numSameVal(std::vector<char> vect1, std::vector<char> vect2);
int LowerNum(std::vector<int> vect1, std::vector<int> vect2, int pos);
void printVector(std::vector <char> const &a);
std::vector<char> stringToVector(std::string s);

#endif //ADVENTOFCODE_DAY3_H
