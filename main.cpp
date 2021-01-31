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

vector<string> fileReadWithVector(const string &fileName){
    // must declare with {""} or else push_back ignore first instance
    vector <string> fileVector = {""};
    string nameCopy;
    ifstream myFile;
    myFile.open(fileName, std::ios::in | std::ios::binary);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        cout << "file found." << endl;
        //print file into vector
        while (myFile >> nameCopy) {
            fileVector.push_back(nameCopy);
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
    return fileVector;
}

int main() {
    string fileName;
    cout << "Enter a number to select a file that you want to read." << endl;
    cout << "1) Frankenstein by Mary Shelley" << endl;
    cout << "2) Jane Eyre by Charlotte Bronte" << endl;
    cout << "Enter here:";
    string bookTitle;
    getline(std::cin, bookTitle);
    while(true){
        if(bookTitle == "1"){
            fileName = "frankenstein.txt";
            break;
        }
        else if(bookTitle == "2"){
            fileName = "jane eyre.txt";
            break;
        }
        else {
            cout << "Program cannot understand." << endl;
            cout << "Please enter only the number to select a file to read.\n" << endl;
            cout << "1) Frankenstein by Mary Shelley" << endl;
            cout << "2) Jane Eyre by Charlotte Bronte" << endl;
            cout << "Enter here: ";
            getline(std::cin, bookTitle);
        }
    }
    StopWatch timer;
    timer.start();
    fileReadWithVector(fileName);
    timer.stop();
    std::cout << "Time to read with vector (seconds): " << timer.timeSecond() << std:: endl;
    std::cout << "Time to read vector (milliseconds): " << timer.timeMilliSec()<< std::endl;

    return 0;
}
