//
//  timer.hpp
//  Goby
//
//  Created by Jonathan Graham on 8/21/19.
//

#ifndef UTILS_TIMER_HPP
#define UTILS_TIMER_HPP

#include <chrono>

class Timer
{
    using high_resolution_clock = std::chrono::high_resolution_clock ;
    using nanoseconds = std::chrono::nanoseconds;
    
public:
    
    Timer();
    ~Timer() = default;
    void reset();
    
    double elapsedNanoseconds();
    double elapsedMicroseconds();
    double elapsedMilliseconds();
    double elapsedSeconds();
    
private:
    high_resolution_clock::time_point m_start;
};

#endif /* UTILS_TIMER_HPP */
