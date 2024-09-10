//
// Created by roach on 05.09.2024.
//
#include "../inc/Timer.h"
// models/src/Timer.cpp
template<typename T, typename... Args>
Timer<T, Args...>::Timer() : methodPtr(nullptr), milliseconds(0)
, isRunning(false), obj(nullptr) {}

template<typename T, typename... Args>
void Timer<T, Args...>::delay() {
    if (!isRunning || methodPtr) return;
    auto start = std::chrono::high_resolution_clock::now();
    while (true) {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        if (duration.count() >= milliseconds)
            break;
    }
}

template<typename T, typename... Args>
void Timer<T, Args...>::run() {
    delay();
    if (!isRunning || !methodPtr || !obj) {
        return; // Early exit if not running, method or object is null
    }

    try {
        auto invokeArgs = std::apply([](auto&&... args) {
            return std::tie(args...);
        }, methodPtr);

        methodPtr(obj, std::forward<decltype(invokeArgs)>(invokeArgs));
    } catch (const std::exception& e) {
        std::cerr << "Error in timer callback: " << e.what() << std::endl;
    }
}

template<typename T, typename... Args>
void Timer<T, Args...>::begin() {
    if (!methodPtr && !obj)
        throw std::runtime_error("Timer hasn't been configured properly");
    isRunning = true;
    run();
}

template<typename T, typename... Args>
void Timer<T, Args...>::stop() {isRunning = false;}

template<typename T, typename... Args>
template<typename Func>
void Timer<T, Args...>::setMethodInstance(Model* instance, Func func,Args... args)
{
    if (!instance)
        throw std::invalid_argument("Invalid instance or method pointer");
    methodPtr = [this, instance, func, args...]() mutable {
        if (!func)
            throw std::runtime_error("Null pointer instance or method");
        return std::invoke(func, instance, std::forward<Args>(args)...);
    };
    obj = instance;
}

template<typename T, typename... Args>
void Timer<T, Args...>::setMethodArguments(Args... args) {
    methodArguments = std::make_tuple(std::forward<Args>(args)...);
}
template<typename T, typename... Args>
void Timer<T, Args...>::setDelay(int milliseconds) {this->milliseconds = milliseconds;}
