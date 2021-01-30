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

    std::chrono::system_clock::time_point start();
    std::chrono::system_clock::time_point stop();
    double milliSec(const std::chrono::system_clock::time_point &start, const std::chrono::system_clock::time_point &stop);
    double sec();
private:
    std::chrono::system_clock::time_point _start;
    std::chrono::system_clock::time_point _stop;
    double _milliSec;
    double _seconds;
};
#endif //CS202_HW1_STOPWATCH_H
