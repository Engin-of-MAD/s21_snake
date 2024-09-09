//
// Created by roach on 05.09.2024.
//

#include <stdexcept>
#include "../inc/Timer.h"

template<typename T>
Timer<T>::Timer() : methodPtr(nullptr), milliseconds(0)
, isRunning(false), obj(nullptr) {}

template <typename T>
void Timer<T>::delay() {
    if (!isRunning || methodPtr) return;
    auto start = std::chrono::high_resolution_clock::now();
    while (true) {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        if (duration.count() >= milliseconds)
            break;
    }
}

template<typename T>
void Timer<T>::run() {
    if (!isRunning && methodPtr && obj) {
        delay();
        methodPtr(obj); // вызов метода по указателю
    }
}

template<typename T>
void Timer<T>::begin() {
    if (!methodPtr && !obj)
        throw std::runtime_error("Timer hasn't been configured properly");
    isRunning = true;
    run();
}

template<typename T>
void Timer<T>::stop() {isRunning = false;}


template<typename T>
void Timer<T>::setMethodInstance(Model* instance, Model* (*func)(Model*))
{
    if (!instance)
        throw std::invalid_argument("Class instance cannot be null");
    methodPtr = func;
    obj = instance;
}
template<typename T>
void Timer<T>::setDelay(int milliseconds) {this->milliseconds = milliseconds;}
