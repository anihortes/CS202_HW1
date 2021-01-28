//
// Created by A. Harrison Owen on 1/28/2021.
//

#include "StopWatch.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <math.h>
using std::cout;
using std::endl;

StopWatch::StopWatch(){
    cout << "Default constructor" << endl;
}

StopWatch::~StopWatch(){
    cout << "Destructor is called on" << endl;
}

double StopWatch::start(){
    auto chronoStartTime = std::chrono::system_clock::now();
    auto duration = std::chrono::duration<double>(chronoStartTime.time_since_epoch());
    auto scaleNum = duration.count()* pow (10,-9);
    _start = scaleNum;
    return _start;
}

double StopWatch::stop(){
    auto chronoStopTime = std::chrono::system_clock::now();
    auto duration = std::chrono::duration<double>(chronoStopTime.time_since_epoch());
    auto scaleNum = duration.count()* pow (10,-9);
    _stop = scaleNum;
    return _stop;
}
