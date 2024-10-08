//
// Created by roach on 12.09.2024.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <iostream>
namespace s21 {
    using Milliseconds = std::chrono::milliseconds;
    using Clock = std::chrono::steady_clock;
    class Timer {
        Milliseconds m_delay;
        Clock::time_point m_currentTime, m_lastUpdateTime;
    public:
        Timer();
        Timer(Milliseconds delay);
        ~Timer() = default;
        bool delay();
        void setCurrentTime(Clock::time_point &&timePoint);
        void setLastUpdateTime(Clock::time_point &&timePoint);
    };
}
#endif //TIMER_H
