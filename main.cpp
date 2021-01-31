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
using std::search;
using std::binary_search;
using std::rotate;
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
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
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
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
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
        //ALWAYS CLOSE FILE WHEN DONE READING
        myFile.close();
    }
    return fileForwardList;
}

void writeToExcel(){
    string nameCopy; // iterates in file, used to copy string in file to container
    std::filebuf fileBuffer;
    fileBuffer.open ("CS201HW1.csv", std::ios::out);
    std::ostream myFile(&fileBuffer);
    if(!myFile){
        cout << "file not found." << endl;
    }
    else {
        //print file into vector
        while (myFile << nameCopy) {

        }
        //ALWAYS CLOSE FILE WHEN DONE READING
        fileBuffer.close();
    }
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

// make vector, print to vector, sort vector
    map<string, int> excelValues;
    StopWatch vectorTimer;
    vector<string> sortedVector;
    sortedVector = fileReadWithVector(fileName);
    vectorTimer.start();
    sort(sortedVector.begin(), sortedVector.end());
    vectorTimer.stop();
    //std::cout << "\nTime to sort with vector (seconds): " << vectorTimer.timeSecond() << std:: endl;
    //std::cout << "Time to sort vector (milliseconds): " << vectorTimer.timeMilliSec()<< std::endl;
    std::pair<string, int>  vectorSort ("Vector sort (ms):", vectorTimer.timeMilliSec());
    excelValues.insert(vectorSort);

    StopWatch listTimer;
    fileReadWithList(fileName);
    list<string> sortedList = fileReadWithList(fileName);
    listTimer.start();
    sortedList.sort();
    listTimer.stop();
    //std::cout << "\nTime to sort with list (seconds): " << listTimer.timeSecond() << std:: endl;
    //std::cout << "Time to sort list (milliseconds): " << listTimer.timeMilliSec()<< std::endl;
    std::pair<string, int>  listSort ("List sort (ms):", listTimer.timeMilliSec());
    excelValues.insert(listSort);

    StopWatch forwardListTimer;
    string randomString;
    forward_list<string> sortedForwardList = fileReadWithForwardList(fileName, randomString, sortedVector.size());
    forwardListTimer.start();
    sortedForwardList.sort();
    forwardListTimer.stop();
    //std::cout << "\nTime to sort with forward_list (seconds): " << forwardListTimer.timeSecond() << std:: endl;
    //std::cout << "Time to sort forward_list (milliseconds): " << forwardListTimer.timeMilliSec()<< std::endl;
    std::pair<string, int>  forwardListSort ("Forward_list sort (ms):", forwardListTimer.timeMilliSec());
    excelValues.insert(forwardListSort);

    vectorTimer.start();
    find(sortedVector.begin(), sortedVector.end(), randomString);
    vectorTimer.stop();
    //std::cout << "\nTime to find random word  with vector (seconds): " << vectorTimer.timeSecond() << std:: endl;
    //std::cout << "Time to find random word  vector (milliseconds): " << vectorTimer.timeMilliSec()<< std::endl;
    excelValues.insert(std::pair("Vector find (ms):", vectorTimer.timeMilliSec()));
    listTimer.start();
    find(sortedList.begin(), sortedList.end(), randomString);
    listTimer.stop();
    //std::cout << "\nTime to find random word  with list (seconds): " << listTimer.timeSecond() << std:: endl;
    //std::cout << "Time to find random word  list (milliseconds): " << listTimer.timeMilliSec()<< std::endl;
    excelValues.insert(std::pair("List find (ms):", listTimer.timeMilliSec()));
    forwardListTimer.start();
    find(sortedForwardList.begin(), sortedForwardList.end(), randomString);
    forwardListTimer.stop();
    //std::cout << "\nTime to find random word with forward_list (seconds): " << forwardListTimer.timeSecond() << std:: endl;
    //std::cout << "Time to find random word  forward_list (milliseconds): " << forwardListTimer.timeMilliSec()<< std::endl;
    excelValues.insert(std::pair("Forward_list find (ms):", forwardListTimer.timeMilliSec()));


    return 0;
}
