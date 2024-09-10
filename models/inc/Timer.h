//
// Created by roach on 05.09.2024.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <functional>
#include <stdexcept>
#include <iostream>
// models/inc/Timer.h
template<typename T, typename... Args>
class Timer {
    using Model = T;
    bool isRunning;
    int milliseconds; // milliseconds;
    Model* obj;
    std::tuple<Args...> methodArguments;
    std::function<void(Model*, Args...)> methodPtr;         // должен храниться указатель на метод класса
    void delay();
public:
    Timer();
    ~Timer() = default;
    void begin();
    void stop();
    void run();
    void setDelay(int milliseconds);

    template<typename Func>
    void setMethodInstance(Model* instance, Func func,Args... args);
    void setMethodArguments(Args... args);
};

#endif //TIMER_H
