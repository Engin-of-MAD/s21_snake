//
// Created by roach on 12.09.2024.
//

#include "../inc/Timer.h"
//models/src/Timer.cpp
namespace s21 {
    Timer::Timer() : m_lastUpdateTime(Clock::now()) {}

    bool Timer::delay(Milliseconds &&timer) {
        auto elapsedTime = std::chrono::duration_cast<Milliseconds>(m_currentTime - m_lastUpdateTime);
        return elapsedTime > timer;
    }

    void Timer::setCurrentTime(Clock::time_point &&timePoint) { m_currentTime = timePoint; }

    void Timer::setLastUpdateTime(Clock::time_point &&timePoint) { m_lastUpdateTime = timePoint; }
}