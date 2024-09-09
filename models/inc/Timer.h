//
// Created by roach on 05.09.2024.
//

#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <functional>
#include <exception>
template<typename T>
class Timer {
    using Model = T;
    bool isRunning;
    int milliseconds; // milliseconds;
    Model* obj;
    std::function<void(Model*)> methodPtr;         // должен храниться указатель на метод класса
    void delay();

public:
    Timer();
    ~Timer() = default;
    void begin();
    void stop();
    void run();
    void setDelay(int milliseconds);
    void setMethodInstance(Model* instance, Model* (*func)(Model*));
};
#endif //TIMER_H
