//
// Created by A. Harrison Owen on 1/28/2021.
//

#ifndef CS202_HW1_STOPWATCH_H
#define CS202_HW1_STOPWATCH_H

#include <iostream>
#include <chrono>
#include <ctime>

class StopWatch{
public:
    StopWatch();
    StopWatch(const std::chrono::system_clock &);
    ~StopWatch();

    double start();
    double stop();
    double milliSec();
    double sec();
private:
    double _start;
    double _stop;
    double _milliSec;
    double _seconds;
};
#endif //CS202_HW1_STOPWATCH_H
