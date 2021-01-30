//
// Created by A. Harrison Owen on 1/28/2021.
//

#include "StopWatch.h"
#include <iostream>
#include <chrono>
#include <math.h>
using std::cout;
using std::endl;

StopWatch::StopWatch(){
    cout << "Default constructor" << endl;
}

StopWatch::~StopWatch(){
    cout << "Destructor is called on" << endl;
}

std::chrono::system_clock::time_point StopWatch::start(){
    auto chronoStartTime = std::chrono::system_clock::now();
    _start = chronoStartTime;
    return chronoStartTime;
}

std::chrono::system_clock::time_point StopWatch::stop(){
    auto chronoStopTime = std::chrono::system_clock::now();
    _stop = chronoStopTime;
    return _stop;
}

double StopWatch::milliSec(const std::chrono::system_clock::time_point &start, const std::chrono::system_clock::time_point &stop){
    auto endTime = std::chrono::duration_cast<std::chrono::microseconds>(stop-start);
    double timeAsDouble = endTime.count();
}