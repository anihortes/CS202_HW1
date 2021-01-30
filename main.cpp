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
    auto t1 = std::chrono::high_resolution_clock::now();
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
        std::cin >> x;
        timer.stop();
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = t2-t1;
        auto endTime = timer.milliSec();
      //  timer.milliSec(timer.start(), timer.stop());
      std::cout << "test time: " << fp_ms.count() << std:: endl;
        std::cout << "time passed: " << endTime << std::endl;
    }
    return 0;
}
