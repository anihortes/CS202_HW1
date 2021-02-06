/*
 * A. Harrison Owen
 * CS 202: Homework 1
 * Professor Hartman
 * 02/05/2021
 */
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
using std::to_string;
#include <list>
using std::list;
#include <forward_list>
using std::forward_list;
#include <algorithm>
using std::sort;
#include <random>
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
#include <map>
using std::map;

//fileName : passed by const reference. used to open file
vector<string> fileReadWithVector(const string &fileName){
    // must declare with {""} or else push_back will ignore first time it's called
    vector <string> fileVector = {""};
    string nameCopy; // iterates in file, used to copy string in file to container
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
    }
    return fileVector;
}

// fileName : passed by const reference. used to open file
list<string> fileReadWithList(const string &fileName){
    std::list<string> fileList;
    string nameCopy; // iterates in file, used to copy string in file to container
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
    }
    return fileList;
}

/*
 * fileName : passed by const reference. used to open file
 * randomString : passed by reference, randomString will be updated
  for when timing is tested to find a word
 * vectorSize : passed by value, used for random number generation
 */
forward_list<string> fileReadWithForwardList(const string &fileName, string &randomString, int vectorSize){\
    //get random number between 1 and number of items in fileVector
    random_device randomStringInFile;
    mt19937 gen(randomStringInFile());
    uniform_int_distribution<>dis(1,vectorSize);
    //make forward_list and write to list from file
    forward_list<string> fileForwardList;
    fileForwardList.assign({""});
    string nameCopy; // iterates in file, used to copy string in file to container
    ifstream myFile;
    myFile.open(fileName, std::ios::in | std::ios::binary);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        //print file into vector
        int stringLocation = 0;
        while (myFile >> nameCopy) {
            fileForwardList.push_front(nameCopy);
            //pulls "random" word out of file
            if(stringLocation == dis(gen)){
                randomString = nameCopy;
            }
                ++stringLocation;
        }
    }
    return fileForwardList;
}
/*
 * containerTimings : passed by const ref
   prints into .csv file
 */
void writeToExcel(const map<string, int> &containerTimings){
    std::filebuf fileBuffer;
    fileBuffer.open ("CS201HW1.csv", std::ios::out);
    std::ostream myFile(&fileBuffer);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        for(const auto &[s,i] : containerTimings)
            myFile << s << ","<<i<<endl;
        fileBuffer.close();
    }
}
void textPrompt(){
    cout << "Enter a number to select a file that you want to read." << endl;
    cout << "1) Frankenstein by Mary Shelley" << endl;
    cout << "2) Jane Eyre by Charlotte Bronte" << endl;
    cout << "3) Dracula by Bram Stoker" << endl;
    cout << "4) Moby Dick by Herman Melville" << endl;
    cout << "5) Beowulf by J. Lesslie Hall" << endl;
    cout << "Enter here:";
}

int main() {
    string fileName;
    textPrompt();
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
        else if(bookTitle == "3"){
            fileName = "dracula.txt";
            break;
        }
        else if(bookTitle == "4"){
            fileName = "moby dick.txt";
            break;
        }
        else if(bookTitle == "5"){
            fileName = "beowulf.txt";
            break;
        }
        else {
            cout << "Program cannot understand." << endl;
            textPrompt();
            getline(std::cin, bookTitle);
        }
    }

// make vector, print to vector, time sort vector, insert into map
    map<string, int> containerTimings;
    StopWatch vectorTimer;
    vector<string> sortedVector;
    sortedVector = fileReadWithVector(fileName);
    vectorTimer.start();
    sort(sortedVector.begin(), sortedVector.end());
    std::pair<string, int>  vectorSort ("Vector sort (ms):", vectorTimer.timeMilliSec());
    containerTimings.insert(vectorSort);
// make list, print to list, time sort list, insert into map
    StopWatch listTimer;
    fileReadWithList(fileName);
    list<string> sortedList = fileReadWithList(fileName);
    listTimer.start();
    sortedList.sort();
    listTimer.stop();
    std::pair<string, int>  listSort ("List sort (ms):", listTimer.timeMilliSec());
    containerTimings.insert(listSort);
// make forward_list, print to forward_list, time sort forward_list,insert into map
    StopWatch forwardListTimer;
    string randomString;
    forward_list<string> sortedForwardList = fileReadWithForwardList(fileName, randomString, sortedVector.size());
    forwardListTimer.start();
    sortedForwardList.sort();
    forwardListTimer.stop();
    std::pair<string, int>  forwardListSort ("Forward_list sort (ms):", forwardListTimer.timeMilliSec());
    containerTimings.insert(forwardListSort);
// time how long it takes to find random string in vector, insert into map
    vectorTimer.start();
    find(sortedVector.begin(), sortedVector.end(), randomString);
    vectorTimer.stop();
    containerTimings.insert(std::pair("Vector find (ms):", vectorTimer.timeMilliSec()));
// time how long it takes to find random string in list, insert into map
    listTimer.start();
    find(sortedList.begin(), sortedList.end(), randomString);
    listTimer.stop();
    containerTimings.insert(std::pair("List find (ms):", listTimer.timeMilliSec()));
// time how long it takes to find random string in forward_list, insert into map
    forwardListTimer.start();
    find(sortedForwardList.begin(), sortedForwardList.end(), randomString);
    forwardListTimer.stop();
    containerTimings.insert(std::pair("Forward_list find (ms):", forwardListTimer.timeMilliSec()));
    writeToExcel(containerTimings);

    return 0;
}
