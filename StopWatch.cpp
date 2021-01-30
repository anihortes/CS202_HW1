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

std::chrono::high_resolution_clock::time_point StopWatch::start(){
    auto chronoStartTime = std::chrono::high_resolution_clock::now();
    _start = chronoStartTime;
    return chronoStartTime;
}

std::chrono::high_resolution_clock::time_point StopWatch::stop(){
    auto chronoStopTime = std::chrono::high_resolution_clock::now();
    _stop = chronoStopTime;
    return _stop;
}

double StopWatch::milliSec(){
    auto endTime = std::chrono::duration<double, std::milli>(_stop - _start).count();
    return endTime;
}