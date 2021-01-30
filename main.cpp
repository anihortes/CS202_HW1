#include "StopWatch.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ifstream;


int main() {

    ifstream myFile;
    string fileName = "big.txt";
    myFile.open(fileName);
    if(!myFile){
        cout << "file not found." << endl;
    }


    //int x;
    //StopWatch timer;
    //timer.start();
    //timer.stop();
    //cout << "Start Time: " << timer.start() << endl;
    //cout << "Stop Time: " << timer.stop() << endl;
    //auto endTime = timer.stop()-timer.start();
    //std::cout << "time passed: " << endTime << std::endl;
    return 0;
}
