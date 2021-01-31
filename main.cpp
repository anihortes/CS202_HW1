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
#include <algorithm>
using std::sort;
using std::search;
using std::binary_search;
using std::rotate;


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
        //print file into vector
        while (myFile >> nameCopy) {
            fileVector.push_back(nameCopy);
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
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
        //print file into vector
        while (myFile >> nameCopy) {
            fileList.push_back(nameCopy);
        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
    return fileList;
}

forward_list<string> fileReadWithForwardList(const string &fileName){
    forward_list<string> fileForwardList;
    fileForwardList.assign({""});
    string nameCopy;
    ifstream myFile;
    myFile.open(fileName, std::ios::in | std::ios::binary);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
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
    vector<string> sortedVector;
    sortedVector = fileReadWithVector(fileName);
    vectorTimer.start();
    sort(sortedVector.begin(), sortedVector.end());
    vectorTimer.stop();
    std::cout << "Time to sort with vector (seconds): " << vectorTimer.timeSecond() << std:: endl;
    std::cout << "Time to sort vector (milliseconds): " << vectorTimer.timeMilliSec()<< std::endl;

    StopWatch listTimer;
    fileReadWithList(fileName);
    list<string> sortedList = fileReadWithList(fileName);
    listTimer.start();
    sortedList.sort();
    listTimer.stop();
    std::cout << "Time to sort with list (seconds): " << listTimer.timeSecond() << std:: endl;
    std::cout << "Time to sort list (milliseconds): " << listTimer.timeMilliSec()<< std::endl;

    StopWatch forwardListTimer;
    forward_list<string> sortedForwardList = fileReadWithForwardList(fileName);
    forwardListTimer.start();
    sortedForwardList.sort();
    forwardListTimer.stop();
    std::cout << "Time to sort with forward_list (seconds): " << forwardListTimer.timeSecond() << std:: endl;
    std::cout << "Time to sort forward_list (milliseconds): " << forwardListTimer.timeMilliSec()<< std::endl;

    return 0;
}
