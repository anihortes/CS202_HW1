#include "StopWatch.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
    int x;
    StopWatch timer;
    timer.start();
    for(auto i = 0; i < 5; ++i){
        cout << "enter a number:" << endl;
        std::cin >> x;
    }
    timer.stop();
    cout << "Start Time: " << timer.start() << endl;
    cout << "Stop Time: " << timer.stop() << endl;
    auto endTime = timer.stop()-timer.start();
    std::cout << "time passed: " << endTime << std::endl;
    return 0;
}
