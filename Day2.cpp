//
// Created by Fernando on 5/4/2023.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Day2.h"

std::vector < std::string > opponentMove;
std::vector < std::string > myMove;


void Day2(){
    std::ifstream datafile;
    std::string currLine;
    int totalScoreOne = 0;
    int totalScoreTwo = 0;
    datafile.open(R"(\Users\fm278\CLionProjects\AdventOfCode\dataDayTwo.txt)");

    while (getline (datafile, currLine)) {
        char currOpponentMove = currLine.at(0);
        char myCurrMove = currLine.at(2);
//        printf("Opponent Move: %c \n", currOpponentMove);
//        printf("My Move: %c \n", myCurrMove);
        switch (myCurrMove){
            case 'X':
                //x == rock == 1
                if(currOpponentMove == 'A'){
                    totalScoreOne = totalScoreOne + 3 + 1;
                } else if(currOpponentMove == 'B'){
                    totalScoreOne = totalScoreOne + 0 + 1;
                } else if( currOpponentMove == 'C') {
                    totalScoreOne = totalScoreOne + 6 + 1;
                }
                break;
            case 'Y':
                //y == paper = 2
                if(currOpponentMove == 'A'){
                    totalScoreOne = totalScoreOne + 6 + 2;
                } else if(currOpponentMove == 'B'){
                    totalScoreOne = totalScoreOne + 3 + 2;
                } else if( currOpponentMove == 'C') {
                    totalScoreOne = totalScoreOne + 0 + 2;
                }
                break;
            case 'Z':
                //Z == scissors = 3
                if(currOpponentMove == 'A'){
                    totalScoreOne = totalScoreOne + 0 + 3;
                } else if(currOpponentMove == 'B'){
                    totalScoreOne = totalScoreOne + 6 + 3;
                } else if( currOpponentMove == 'C') {
                    totalScoreOne = totalScoreOne + 3 + 3;
                }
                break;
        }

        switch (currOpponentMove){
            case 'A':
                //x == rock == 1
                if(myCurrMove == 'X'){
                    totalScoreTwo = totalScoreTwo + 0 + 3;
                } else if(myCurrMove == 'Y'){
                    totalScoreTwo = totalScoreTwo + 3 + 1;
                } else if( myCurrMove == 'Z') {
                    totalScoreTwo = totalScoreTwo + 6 + 2;
                }
                break;
            case 'B':
                //y == paper = 2
                if(myCurrMove == 'X'){
                    totalScoreTwo = totalScoreTwo + 0 + 1;
                } else if(myCurrMove == 'Y'){
                    totalScoreTwo = totalScoreTwo + 3 + 2;
                } else if( myCurrMove == 'Z') {
                    totalScoreTwo = totalScoreTwo + 6 + 3;
                }
                break;
            case 'C':
                //Z == scissors = 3
                if(myCurrMove == 'X'){
                    totalScoreTwo = totalScoreTwo + 0 + 2;
                } else if(myCurrMove == 'Y'){
                    totalScoreTwo = totalScoreTwo + 3 + 3;
                } else if( myCurrMove == 'Z') {
                    totalScoreTwo = totalScoreTwo + 6 + 1;
                }
                break;
        }
    }
    printf("Total score with strat 1: %d \n", totalScoreOne);
    printf("Total score with strat 2: %d \n", totalScoreTwo);
}
