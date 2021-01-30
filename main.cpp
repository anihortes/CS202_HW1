#include "StopWatch.h"
#include <iostream>
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;


int main() {
    StopWatch timer;
    timer.start();
    // must declare with {""} or else push_back ignore first instance
    vector <string> fileVector = {""};
    string nameCopy;
    ifstream myFile;
    string fileName = "big.txt";
    myFile.open(fileName, std::ios::in | std::ios::binary);
    if(!myFile){
        cout << "file not found." << endl;
        return 0;
    }
    else {
        cout << "file found." << endl;
        //print file into vector
        while(myFile >> nameCopy){
            cout << "test: " << nameCopy << endl;
            fileVector.push_back(nameCopy);
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();

        int x;
        timer.stop();
        auto endTime = timer.stop()-timer.start();
      //  timer.milliSec(timer.start(), timer.stop());
        std::cout << "time passed: " << timer.milliSec(timer.start(), timer.stop()) << std::endl;
    }
    return 0;
}
