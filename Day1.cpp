#include <iostream>
#include <fstream>
#include <string>

void dayOne(){
    std::ifstream datafile;
    std::string currLine;
    datafile.open(R"(\Users\fm278\CLionProjects\AdventOfCode\dataDayOne.txt)");
    // Use a while loop together with the getline() function to read the file line by line
    int sum = 0;
    int firstHighest = 0;
    int secondHighest = 0;
    int thirdHighest = 0;
    if(datafile.is_open()){
        while (getline (datafile, currLine)) {
            if (currLine.empty()){
                if(firstHighest < sum) {
                    thirdHighest = secondHighest;
                    secondHighest = firstHighest;
                    firstHighest = sum;
                }
                else if(secondHighest < sum){
                    thirdHighest = secondHighest;
                    secondHighest = sum;
                }
                else if(thirdHighest < sum){
                    thirdHighest = sum;
                }
                sum = 0;
            }else{
                int curr = stoi(currLine);
                sum += curr;
            }
        }
    }else{
        std::cout << "why just why";
    }

    std::cout << firstHighest + secondHighest + thirdHighest << std::endl;

// Close the file
    datafile.close();
}
