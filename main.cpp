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
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;

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
    fileVector[1].find("the");
    return fileVector;
}

list<string> fileReadWithList(const string &fileName){
    std::list<string> fileList;
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
            fileList.push_back(nameCopy);
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
    return fileList;
}

forward_list<string> readFilewithForward_List(const string &fileName){
    forward_list<string> fileForwardList;
    fileForwardList.assign({""});
    string nameCopy;
    ifstream myFile;
    myFile.open(fileName, std::ios::in | std::ios::binary);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        cout << "file found." << endl;
        //print file into vector
        int nthPlaceInList = 0;
        while (myFile >> nameCopy) {
            fileForwardList.push_front(nameCopy);
            nthPlaceInList ++;
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
    return fileForwardList;
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
    StopWatch vectorTimer;
    vectorTimer.start();
    fileReadWithVector(fileName);
    vectorTimer.stop();
    std::cout << "Time to read with vector (seconds): " << vectorTimer.timeSecond() << std:: endl;
    std::cout << "Time to read vector (milliseconds): " << vectorTimer.timeMilliSec()<< std::endl;
    StopWatch listTimer;
    listTimer.start();
    fileReadWithList(fileName);
    listTimer.stop();
    std::cout << "Time to read with list (seconds): " << listTimer.timeSecond() << std:: endl;
    std::cout << "Time to read list (milliseconds): " << listTimer.timeMilliSec()<< std::endl;
    StopWatch forwardListTimer;
    forwardListTimer.start();
    fileReadWithList(fileName);
    forwardListTimer.stop();
    std::cout << "Time to read with forward_list (seconds): " << forwardListTimer.timeSecond() << std:: endl;
    std::cout << "Time to read forward_list (milliseconds): " << forwardListTimer.timeMilliSec()<< std::endl;

    return 0;
}
