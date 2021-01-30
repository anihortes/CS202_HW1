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

double StopWatch::start(){
    auto chronoStartTime = std::chrono::system_clock::now();
    auto t_c = std::chrono::system_clock::to_time_t(chronoStartTime-std::chrono::seconds(86400));
    std::localtime(&t_c);
    std::chrono::seconds test;
    auto duration = std::chrono::duration<double>(chronoStartTime.time_since_epoch());
    auto scaleNum = test.count();
    _start = scaleNum;
    return _start;
}

double StopWatch::stop(){
    auto chronoStopTime = std::chrono::system_clock::now();
    std::chrono::seconds test;
    auto duration = std::chrono::duration<double>(chronoStopTime.time_since_epoch());
    auto scaleNum = test.count();
    _stop = scaleNum;
    return _stop;
}
